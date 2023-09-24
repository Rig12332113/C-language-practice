#include <stdio.h>
#include <stdlib.h>
int num = 0;
int numbers[50];
int compare(const void *a, const void *b){
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a == *(int *)b)
        return 0;
    else 
        return -1;
}
void print(int index, int size){
    if (size == 1){
        for(int i = 0; i < num; i++){
            if (i == num - 1)
                printf("%d\n", *(numbers + i));
            else    
                printf("%d ", *(numbers + i));
        }
    }
    else{
        for(int i = 0; i <= size; i++){
            if (i < size){
                int temp = *(numbers + index + i);
                *(numbers + index + i) = *(numbers + index);    
                *(numbers + index) = temp;
                print(index + 1, size - 1);
            }
            else
                qsort(numbers + index, size, sizeof(int), compare);
        }
    }
}
void test(){
    *numbers = 100000;
}
int main(void){
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf("%d", (numbers + i));
    qsort(numbers, num, sizeof(int), compare);
    print(0, num);
    //for(int i = 0; i < num; i++)
        //printf("%d ", *(numbers + i));
    return 0;
}