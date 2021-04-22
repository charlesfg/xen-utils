#!/usr/bin/python
"""
This script will receive:
    pid - pid of the process to evaluate
    range - one of heap|stack|vdso
    order - first | last| random

And return the related page address

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
    def __init__(self, pfn):
        self.pfn = pfn
        self.mfn = None
        self.present = 0
        self.file_mapped = 0
        self.pm_entry = None

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

    def set_pm_entry(self, entry):
        self.pm_entry = entry
        self.present = self.is_present(entry)
        self.file_mapped = self.is_file_page(entry)
        if self.present:
            self.mfn = self.get_pfn(entry)


class PageMapHandler:
    def __init__(self, pid):
        self.pid = pid
        self.pg_sz = os.sysconf("SC_PAGE_SIZE")
        self.pagemaps_path = "/proc/{0}/pagemap".format(pid)
        self.maps_path = "/proc/{0}/maps".format(pid)
        if not os.path.isfile(self.pagemaps_path) or not os.path.isfile(self.maps_path):
            raise ValueError("Process {0} doen not exist!".format(self.pid))

        self.all_mem_entries = []
        self.all_mfn = []

    def getAddrRange(self, area):
        with open(self.maps_path, 'r') as f:
            for i in f.readlines():
                fields = i.split()
                if area in fields[-1]:
                    addrs = fields[0].split('-')
                    if DEBUG:
                        print(fields)
                        print(addrs)
                    return int(addrs[0], 16), int(addrs[1], 16)

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
                i.set_pm_entry(struct.unpack('Q', f.read(size))[0])
                if DEBUG:
                    print(i)

        pass

    def get_page(self, order):
        if order == 'first':
            for i in self.all_mem_entries: #
                if i.mfn is not None:
                    return i
            pass
        elif order == 'last':
            self.all_mem_entries.reverse()
            for i in self.all_mem_entries: #
                if i.mfn is not None:
                    return i
            pass
        elif order == 'random':
            while True:
                i = random.choice(self.all_mem_entries)
                if i.mfn is not None:
                    return i
            pass
        else:
            ValueError("This is impossible. How could I ended up here!?")
        pass


if __name__ == '__main__':

    if os.geteuid() != 0:
        exit("You need to have root privileges to run this script.\n"
             "Please try again, this time using 'sudo'. Exiting.")

    parser = argparse.ArgumentParser(
        description='Script to get a physical page address given a pid and a specification\n'
                    'Must be root to run this p')
    parser.add_argument('--pid', '-p', metavar='pid', type=int, required=True, help='Pid of the Process')
    parser.add_argument('--region', '-r', metavar='memory_regions', type=str, choices=('stack', 'heap', 'vdso', 'vvar'),
                        required=True, help='Area from possible addresses to obtain, one of: %(choices)s', )
    parser.add_argument('--order','-o', metavar='page-order', type=str, choices=('first', 'last', 'random'),
                        default='first', required=True,
                        help='The order of the page to return, one of: %(choices)s')
    parser.add_argument('--debug', '-d', action='store_true', required=False, default=False,
                        help='Enable printing debug messages')
    parser.add_argument('--quiet', '-q', action='store_true', required=False, default=False,
                        help='Only print the mfn of the page')

    args = parser.parse_args()

    DEBUG = args.debug

    pmh = PageMapHandler(args.pid)
    saddr, eaddr = pmh.getAddrRange(args.region)
    if DEBUG:
        print("Address of {2} {0:#x}, {1:#x}".format(saddr, eaddr, args.region))
    pmh.generate_all_pages(saddr, eaddr)
    pmh.update_entries()
    page = pmh.get_page(args.order)
    if args.quiet:
        print("{:#x}".format(page.mfn))
    else:
        print(page)
