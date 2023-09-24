#include<stdio.h>
#include "snake.h"
int snake(int *ptr, int *row, int *column){
    int num = 1;
    while(*(ptr + num) != 0){
        num++;
    }
    for (int i = 0; i <= num; i++)
        if (*(ptr + i) != i){
            *column = i;
            break;
        }
    *row = num / *column;
    for(int i  = 0; i < *row; i++){
        for(int j = 0; j < *column; j++){
            if (i % 2 == 0){
                if (ptr[i * *(column) + j] != i * *(column) + j){
                    *row = i;
                    *column = j;
                    return 0;
                }
            }
            else{
                if (ptr[i * *(column) + j] != i * *(column) + *(column) - j - 1){
                    *row = i;
                    *column = *column - j - 1;
                    return 0;
                }
            }
        }
    }
    return 1;
}