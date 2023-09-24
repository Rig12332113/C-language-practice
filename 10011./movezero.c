#include <stdio.h>
#include <stdlib.h>
int main(void){
    int size = 0;
    scanf("%d", &size);
    int *data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        scanf("%d", data + i);
    int place = 0;
    for (int i = 0; i < size; i++){
        if (data[i] != 0){
            int temp = data[i];
            data[i] = 0;
            data[place] = temp;
            place++;
        }
    }
    for (int i = 0; i < size; i++){
        if (i == size - 1)
            printf("%d\n", data[i]);
        else
            printf("%d ", data[i]);
    }
    return 0;
}