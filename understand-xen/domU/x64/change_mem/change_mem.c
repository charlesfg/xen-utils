#include <stdint.h>
#include <stdio.h>

int main(){

    uintptr_t i = 0;
    printf("i: %ld\t&i: %p\n", i,&i); 
    while(1){
        printf("Insert a memory addres\n");
        scanf("%lX", &i);
        printf("Value read: ");
        printf("i: %lX\t&i: %ld\n", i, *(uint64_t*)i); 
    }
    
}

