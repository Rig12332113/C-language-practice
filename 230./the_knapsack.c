#include <stdio.h>
#include <stdlib.h>
int compute(int *weight, int *value, int num ,int limit){
    if (num == 0)
        return 0;
    else if (*weight > limit)
        return compute(weight + 1, value + 1, num - 1, limit);
    else{
        int nottake = compute(weight + 1, value + 1, num - 1, limit);
        int take = *value + compute(weight + 1, value + 1, num - 1, limit - *weight);
        return nottake > take ? nottake : take;
    }
}
int main(void){
    int num = 0, limit = 0;
    scanf("%d%d", &num, &limit);
    int *weight = (int *)malloc(sizeof(int) * num);
    int *value = (int *)malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++)
        scanf("%d%d", (weight + i), (value + i));
    
    printf("%d", compute(weight, value, num, limit));
    return 0;
}