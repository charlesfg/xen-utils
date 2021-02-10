#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int  main()
{
    int i = 18012016;
    int pid = getpid();
    printf("pid %d\tvar %d\t va %p\n",pid, i, &i);
    for(;;)
    {
        char input = getchar();
        switch (input)
        {
            case 'q':
                printf("Quiting... \n");
                return 0;
            default:
                printf("pid %d\tvar %d\t va %p\n",pid, i, &i);

        }
            
    }
}
