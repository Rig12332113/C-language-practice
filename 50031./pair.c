#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
typedef struct point
{
    int index, number;
}Point;
typedef struct pair
{
    int sum, index1, index2;
}Pair;
int compare1(const void*a, const void *b){
    if (((Point *)a)->number > ((Point *)b)->number)
        return 1;
    else if (((Point *)a)->number < ((Point *)b)->number)
        return -1;
    else if (((Point *)a)->index > ((Point *)b)->index)
        return 1;    
    else if (((Point *)a)->index < ((Point *)b)->index)
        return -1;
    else 
        return 0;
}
int compare2(const void*a, const void *b){
    if (((Pair *)a)->sum > ((Pair *)b)->sum)
        return 1;
    else if (((Pair *)a)->sum < ((Pair *)b)->sum)
        return -1;
    else if (((Pair *)a)->index1 > ((Pair *)b)->index1)
        return 1;    
    else if (((Pair *)a)->index1 < ((Pair *)b)->index1)
        return -1;
    else 
        return 0;
}
void pairPrint(int numbers[], int n){
    Point *data = (Point *)malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i ++){
        data[i].index = i;
        data[i].number = numbers[i];
    }
    qsort(data, n, sizeof(Point), compare1);
    Pair *answer = (Pair *)malloc(sizeof(Pair) * n / 2);
    for(int i = 0; i < n / 2; i++){
        answer[i].sum = data[i].number + data[n - 1 - i].number;
        answer[i].index1 = data[i].index < data[n - 1 - i].index ? data[i].index : data[n - 1 - i].index;
        answer[i].index2 = data[i].index > data[n - 1 - i].index ? data[i].index : data[n - 1 - i].index;;
    }
    qsort(answer, n / 2, sizeof(Pair), compare2);
    free(data);
    #ifdef INC
        for (int i = 0; i < n / 2; i++){
            printf("%d = numbers[%d] + numbers[%d]\n", answer[i].sum, answer[i].index1, answer[i].index2);
        }
    #endif
    #ifdef DEC
        for (int i = n / 2 - 1; i >= 0; i--){
            printf("%d = numbers[%d] + numbers[%d]\n", answer[i].sum, answer[i].index2, answer[i].index1);
        }
    #endif
    free(answer);
}