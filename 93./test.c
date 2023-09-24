#include "heap.h"
#include "heap.c"
#include <stdio.h>
int main(void){
    struct Heap data;
    int cmd = 0;
    while(scanf("%d", &cmd) != EOF){
        if (cmd == 0)
            initialize(&data);
        else if (cmd == 1)
            printf("%d \n", removeMin(&data));
        else if (cmd == 2){
            int input = 0;
            scanf("%d", &input);
            add(&data, input); 
        }  
        else if (cmd == 3)
            printf("%d\n", isFull(&data));
        else if (cmd == 4)
            printf("%d\n", isEmpty(&data)); 
        printf("(%d)", data.num);
    }
    return 0;
}