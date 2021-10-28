#!/usr/bin/python
"""
This script will receive:
    pid - pid of the process to evaluate
    range - one of heap|stack|vdso
    order - first | last| random

And return the related page address

The return is the mfn on the current context. 
BEWARE:  if running on a VM environment this can not
necessearly mean the real physical address.

"""

import argparse
import sys
import os
import binascii
import struct
from enum import Enum
import ctypes
import random

# PAGE_SHIFT = ctypes.c_ulong(12)
# PAGE_SIZE = (ctypes.c_ulong(1) << PAGE_SHIFT )
# PAGE_MASK = (~(PAGE_SIZE-1))
PAGE_SHIFT = 12
PAGE_SIZE = 1 << PAGE_SHIFT
PAGE_MASK = (~(PAGE_SIZE - 1))
DEBUG = False


#
#
# print("PAGE_SHIFT {}".format(PAGE_SHIFT))
# print("PAGE_SIZE {0:x}".format(PAGE_SIZE))
# print("PAGE_MASK {0:#x}".format(PAGE_MASK))
#
# exit(0)

class PageEntry:
    def __init__(self, addr, entry):
        self.addr = addr
        self.pfn = (addr >> PAGE_SHIFT)
        self.mfn = None
        self.pm_entry = entry
        if entry is None:
            self.present = 0 
            self.file_mapped = 0 
        else:
            self.present = self.is_present(entry)
            self.file_mapped = self.is_file_page(entry)
            if self.present:
                self.mfn = self.get_pfn(entry)

    def is_present(self, entry):
        return ((entry & (1 << 63)) != 0)

    def is_file_page(self, entry):
        return ((entry & (1 << 61)) != 0)

    def get_pfn(self, entry):
        return entry & 0x7FFFFFFFFFFFFF

    def __str__(self):
        if self.mfn is None:
            mfn_p = "-"
        else:
            mfn_p = "{:#x}".format(self.mfn)

        return "pfn {0:#x} - mfn {1} : [present({2:b})|file_mapped({3:b})] - pm entry {4:#x}".format(
            self.pfn, mfn_p, self.present, self.file_mapped, self.pm_entry
        )


class PageMapHandler:
    def __init__(self, pid):
        self.pid = pid
        self.pg_sz = os.sysconf("SC_PAGE_SIZE")
        self.pagemaps_path = "/proc/{0}/pagemap".format(pid)
        self.pagemap_entry_size = 8

        if not os.path.isfile(self.pagemaps_path):
            raise ValueError("Process {0} doesn't exist.".format(self.pid))

        self.maps_path = "/proc/{0}/maps".format(pid)
        if not os.path.isfile(self.pagemaps_path) or not os.path.isfile(self.maps_path):
            raise ValueError("Process {0} does not exist!".format(self.pid))

        self.all_mem_entries = []
        self.all_addresses = []
        self.all_mfn = []
        # will hold a typle of initial mfn, end mfn for maps document
        self.maps_mfn_version = []

    def get_pagemap_entry(self, addr):
        offset = int((addr / self.pg_sz) * self.pagemap_entry_size)
        entry = None
        with open(self.pagemaps_path, 'rb') as f:
            f.seek(offset, 0)
            try:
                entry = struct.unpack('q', f.read(self.pagemap_entry_size))[0]
            except:
                print("error on getting PE for addr {}".format(addr))
        
        return entry


    def print_mfn_maps_version(self):
        with open(self.maps_path, 'r') as f:
            for i in f.readlines():
                fields = list(map(str.strip, i.split()))
                addrs = fields[0].split('-')
                if DEBUG:
                    print(fields)
                    print(addrs)
                
                saddr = int(addrs[0], 16)
                eaddr = int(addrs[1], 16)
                s_pe = PageEntry(saddr, self.get_pagemap_entry(saddr))
                e_pe = PageEntry(eaddr, self.get_pagemap_entry(eaddr))
                
                print("{:#x} : {} ".format(saddr, s_pe))
                print("{:#x} : {} ".format(eaddr, e_pe))
                print(i)
                print("=" * 50)

    def print_memory_limits(self):
        with open(self.maps_path, 'r') as f:
            for i in f.readlines():
                fields = list(map(str.strip, i.split()))
                addrs = fields[0].split('-')
                if DEBUG:
                    print(fields)
                    print(addrs)
                
                saddr = int(addrs[0], 16)
                eaddr = int(addrs[1], 16)
                self.generate_all_pages_addresses(saddr, eaddr)
        
        for i in self.all_addresses:
            pe = PageEntry(i, self.get_pagemap_entry(i))
            if pe.mfn:
                self.all_mfn.append(pe.mfn)

        self.all_mfn.sort()
        mfn_sorted = self.all_mfn
        print("num of valid mfn {}".format(len(mfn_sorted)))
        print("limits 0x{:x} 0x{:x}".format(mfn_sorted[0],mfn_sorted[-1]))





    def getExecAddrRanges(self):
        with open(self.maps_path, 'r') as f:
            for i in f.readlines():
                fields = list(map(str.strip, i.split()))
                if 'xp' in fields[1]:
                    addrs = fields[0].split('-')
                    if DEBUG:
                        print(fields)
                        print(addrs)
                    yield int(addrs[0], 16), int(addrs[1], 16)

    def getAddrRange(self, area):
        if area == 'exec':
            with open(self.maps_path, 'r') as f:
                for i in f.readlines():
                    fields = list(map(str.strip, i.split()))
                    if not fields[-1] or '.so' in fields[-1]:
                        continue
                    if 'xp' in fields[1] and '/' in fields[-1]:
                        addrs = fields[0].split('-')
                        if DEBUG:
                            print(fields)
                            print(addrs)
                        return int(addrs[0], 16), int(addrs[1], 16)
        else:
            with open(self.maps_path, 'r') as f:
                for i in f.readlines():
                    fields = i.split()
                    if area in fields[-1]:
                        addrs = fields[0].split('-')
                        if DEBUG:
                            print(fields)
                            print(addrs)
                        return int(addrs[0], 16), int(addrs[1], 16)

    def generate_all_pages_addresses(self, saddr, eaddr):

        st_pfn = saddr >> PAGE_SHIFT
        st_off = saddr & ~PAGE_MASK

        en_pfn = eaddr >> PAGE_SHIFT
        en_off = eaddr & ~PAGE_MASK

        pfn = en_pfn - st_pfn

        if DEBUG:
            print("STartAddress: %#x" % saddr)
            print("pfn: %#x" % st_pfn)
            print("off: %#x" % st_off)

            print("End Address: %#x" % saddr)
            print("pfn: %#x" % en_pfn)
            print("off: %#x" % en_off)

            print("Numero pgs: %d" % (pfn))

        while st_pfn < en_pfn:
            self.all_addresses.append(st_pfn << PAGE_SHIFT)
            st_pfn += 1

        self.all_addresses.append(en_pfn << PAGE_SHIFT)
        pass

    def generate_all_pages(self, saddr, eaddr):

        st_pfn = saddr >> PAGE_SHIFT
        st_off = saddr & ~PAGE_MASK

        en_pfn = eaddr >> PAGE_SHIFT
        en_off = eaddr & ~PAGE_MASK

        pfn = en_pfn - st_pfn

        if DEBUG:
            print("STartAddress: %#x" % saddr)
            print("pfn: %#x" % st_pfn)
            print("off: %#x" % st_off)

            print("End Address: %#x" % saddr)
            print("pfn: %#x" % en_pfn)
            print("off: %#x" % en_off)

            print("Numero pgs: %d" % (pfn))

        while st_pfn < en_pfn:
            self.all_mem_entries.append(PageEntry(st_pfn))
            st_pfn += 1

        self.all_mem_entries.append(PageEntry(en_pfn))
        pass

    def update_entries(self, size=8):
        with open(self.pagemaps_path, 'rb') as f:
            for i in self.all_mem_entries:
                f.seek(i.pfn * size, 0)
                pm_entry = None
                try: 
                    pm_entry = struct.unpack('Q', f.read(size))[0]
                    i.set_pm_entry(pm_entry)
                    if DEBUG:
                        print(i)
                except:
                    if DEBUG:
                        print("!! ERROR for pfn {}! Skipping it!".format(i.pfn))

        pass

    def get_pages(self, order):
        if order == 'first':
            for i in self.all_mem_entries: #
                if i.mfn is not None:
                    return [i]
            pass
        elif order == 'last':
            self.all_mem_entries.reverse()
            for i in self.all_mem_entries: #
                if i.mfn is not None:
                    return [i]
            pass
        elif order == 'all':
            return self.all_mem_entries
            pass
        elif order == 'random':
            while True:
                i = random.choice(self.all_mem_entries)
                if i.mfn is not None:
                    return [i]
            pass
        else:
            ValueError("This is impossible. How could I ended up here!?")
        pass


if __name__ == '__main__':

    if os.geteuid() != 0:
        exit("You need to have root privileges to run this script.\n"
             "Please try again, this time using 'sudo'. Exiting.")

    parser = argparse.ArgumentParser(
        description='Script to get a physical page address (in the current context)' 
                    'given a pid and a specification\n'
                    'Must be root to run this p')
    parser.add_argument('--pid', '-p', metavar='pid', type=int, required=True, help='Pid of the Process')
    parser.add_argument('--summary', '-s',  action='store_true', required=False, help='Ignore all options beside Pid. Print the mfn version of /proc/<pid>/maps file')
    parser.add_argument('--region', '-r', metavar='memory_regions', type=str, choices=('stack', 'heap', 'vdso', 'vvar', 'exec'),
                        required=True, help='Area from possible addresses to obtain, one of: %(choices)s', )
    parser.add_argument('--order','-o', metavar='page-order', type=str, choices=('first', 'last', 'random', 'all'), default='first',
                        help='The order of the page to return, one of: %(choices)s')
    parser.add_argument('--debug', '-d', action='store_true', required=False, default=False,
                        help='Enable printing debug messages')
    parser.add_argument('--verbose', '-v', action='store_true', required=False, default=False,
                        help='Print additional information')

    args = parser.parse_args()

    DEBUG = args.debug

    pmh = PageMapHandler(args.pid)

    if args.summary:
        #        pmh.print_mfn_maps_version()
        pmh.print_memory_limits()
        exit(0)

    elif args.region == 'exec':
        for saddr, eaddr in pmh.getExecAddrRanges():
            if DEBUG:
                print("Address of {2} {0:#x}, {1:#x}".format(saddr, eaddr, args.region))
            pmh.generate_all_pages(saddr, eaddr)
    else:
        saddr, eaddr = pmh.getAddrRange(args.region)
        if DEBUG:
            print("Address of {2} {0:#x}, {1:#x}".format(saddr, eaddr, args.region))
        pmh.generate_all_pages(saddr, eaddr)

    pmh.update_entries()
    pages= pmh.get_pages(args.order)

    for p in pages:
        if not args.verbose:
            if p.mfn:
                print("{:#x}".format(p.mfn))
        else:
            print(p)

