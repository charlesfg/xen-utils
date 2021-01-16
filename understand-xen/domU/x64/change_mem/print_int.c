#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




void main()
{
    int i = 18012016;
    printf("var %d\t va %p\n", i, &i);
    for(;;)
    {
        char input = getchar();
        switch (input)
        {
            case 'q':
                printf("Quiting... \n");
                return;
            default:
                printf("var %d\t va %p\n", i, &i);

        }
            
    }
}
