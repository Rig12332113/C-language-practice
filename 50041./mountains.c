#include <stdio.h>
#include <stdlib.h>
int main(void){
    int num = 0;
    scanf("%d", &num);
    int cases = 1, fuel = 0, type = 0, type_previous = 0;
    int current = 0;
    scanf("%d", &current);
    while(cases < num){
        int next = 0;
        scanf("%d", &next); 
        type = current < next ? 1 : 0;      //1 for uphill, 0 for downhill
        if (cases == 1){
            if (type)
                fuel += 3 * abs(current - next);
            else
                fuel += 2 * abs(current - next);
        }
        else{
            if (type && type_previous)
                fuel += 4 * abs(current - next);
            else if (type && !type_previous)
                fuel += 3 * abs(current - next);
            else if (!type && type_previous)
                fuel += 3 * abs(current - next);
            else
                fuel += 2 * abs(current - next);
        }
        current = next;
        type_previous = type;
        cases++;
    }
    printf("%d", fuel);
    return 0;
}