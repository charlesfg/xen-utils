#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

unsigned long* get_aligned_value(unsigned long v){

    unsigned long *p, *t;
    p = aligned_alloc(PAGE_SIZE,PAGE_SIZE/(sizeof(unsigned long)));
    t = p;
    for(int i =0; i< (PAGE_SIZE/(sizeof(unsigned long))); i++){
        *t++ = v;
    }
    return p;
}


int  main()
{
    unsigned long  i = 18012016;
    unsigned long  *p;

    int pid = getpid();
    p = get_aligned_value(i);
    printf("[stack] pid %d\tvar %ld\t va %p\n",pid, i, &i);
    printf("+[heap] pid %d\tvar %ld\t va %p\n",pid, *p, p);
    for(;;)
    {
        char input = getchar();
        switch (input)
        {
            case 'q':
                printf("Quiting... \n");
                free(p);
                return 0;
            default:
                printf("pid %d\tvar %ld\t va %p\n",pid, *p, p);

        }
            
    }

}
