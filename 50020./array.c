#include "array.h"
void init(ARRAY *a,  int left, int right){
    a->start = left;
    a->end = right;
    for(int i = 0; i <= right - left; i++){
        a->array[i] = -2147483647;
    }
}
int set(ARRAY *a, int index, int value){
    if (index < a->start || index > a->end)
        return -2147483648;
    else{
        a->array[index - a->start] = value;
        return 1;
    }
}
int get(ARRAY *a, int index){
    if (index < a->start || index > a->end)
        return -2147483648;
    else
        return a->array[index - a->start];
}
void print(ARRAY *a){
    for(int i = 0; i <= a->end - a->start; i++){
        if (a->array[i] == -2147483647)
            printf("No value\n");
        else
            printf("%d\n", a->array[i]);
    }
}
void sort(ARRAY *a){
    for(int i = 0; i <= a->end - a->start; i++){
        for(int j = 0; j <= a->end - a->start; j++){
            int temp;
            if (a->array[i] < a->array[j]){
                temp = a->array[i];
                a->array[i] = a->array[j];
                a->array[j] = temp;
            }
        }
    }
}
 