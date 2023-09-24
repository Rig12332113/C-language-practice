#include <stdio.h>
#include "card.h"
void shuffle(int *deck[]){
    int num = 0;
    int *data[10000];
    while(deck[num] != NULL){
        data[num] = deck[num];
        num++;
    }
    int m = 0, n = 0;
    for(int i = 0; i < num; i++){
        if (i % 2 == 0){
            deck[i] = data[m];
            m++;
        }
        else{
            deck[i] = data[(num + 1) / 2 + n];
            n++;
        }
    }
}
void print(int *deck[]){
    int num = 0;
    while(deck[num] != NULL){
        printf("%d ", *deck[num]);
        num++;
    }
}