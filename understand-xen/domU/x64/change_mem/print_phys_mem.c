#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "inttypes.h"

uintptr_t vtop(uintptr_t vaddr) {
    FILE *pagemap;
    intptr_t paddr = 0;
    int offset = (vaddr / sysconf(_SC_PAGESIZE)) * sizeof(uint64_t);
    uint64_t e;

    // https://www.kernel.org/doc/Documentation/vm/pagemap.txt
    if ((pagemap = fopen("/proc/self/pagemap", "r"))) {
        if (lseek(fileno(pagemap), offset, SEEK_SET) == offset) {
            if (fread(&e, sizeof(uint64_t), 1, pagemap)) {
                if (e & (1ULL << 63)) { // page present ?
                    paddr = e & ((1ULL << 54) - 1); // pfn mask
                    paddr = paddr * sysconf(_SC_PAGESIZE);
                    // add offset within page
                    paddr = paddr | (vaddr & (sysconf(_SC_PAGESIZE) - 1));
                }   
            }   
        }   
        fclose(pagemap);
    }   

    return paddr;
}   


int main(int argc, char** argv)
{

    if(argc != 2)
    {
        printf("Usage: virt2phys [va virtual address]\n");
        return -1;
    }
    int a = 1;
    unsigned long va =  strtol(argv[1],NULL,16);
    printf("Address passed 0x%lx\t%p\n",va, (void*) va );

    printf("Physical Address:\t%p\n",(void *) vtop(&a));

    return 0;

}
