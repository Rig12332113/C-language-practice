#include "blockmover.h"
long long int leftbound = 1, rightbound = 1 << 7;
void printBlock(unsigned long long int *block){
    int temp = 1;
    for(int i = 0; i < 64; i++){
        if (i % 8 == 7)
            printf("%llu\n", *block >> i & temp);
        else
            printf("%llu", *block >> i & temp);
    }
}
void initialize(unsigned long long int *block, int row, int column, int size){
    int temp = 1;
    for(int i = 1; i < size; i++)
        temp = temp | temp << 1;
    *block = temp;
    for(int i = 1; i < size; i++)
        *block = *block << 8 | temp;
    *block = *block <<  column;
    for(int i = 0; i < row; i++)
        *block = *block << 8;
}
int moveLeft(unsigned long long int *block){
    if (leftbound == 1)
        for(int i = 0; i < 8; i++)
            leftbound = 1 | leftbound << 8;
    if ((*block & leftbound) > 0)
        return 0;
    else{
        *block = *block >> 1;
        return 1;
    }
}
int moveRight(unsigned long long int *block){
    if (rightbound == 1 << 7)
        for(int i = 0; i < 8; i++)
            rightbound = 1 << 7 | rightbound << 8;
    if ((*block & rightbound) > 0)
        return 0;
    else{
        *block = *block << 1;
        return 1;
    }
}
int moveUp(unsigned long long int *block){
    long long topbound = 255;
    if ((*block & topbound) > 0)
        return 0;
    else{
        *block = *block >> 8;
        return 1;
    }
}
int moveDown(unsigned long long int *block){
    long long int bottombound = 255;
    bottombound = bottombound << 56;
    if ((*block & bottombound) > 0)
        return 0;
    else{
        *block = *block << 8;
        return 1;
    }
}