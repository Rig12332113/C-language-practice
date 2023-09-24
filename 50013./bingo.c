#include "bingo.h"
long long int topleft = 1, topright = 1;
int bingo(const unsigned long long int *board, int *rowColumn){
    for(int i = 0; i < 8; i++)
        topleft = topleft << 9 | 1;
    topright = topright << 7;
    for(int i = 0; i < 8; i++)
        topright = topright << 7 | 128;
    long long int straight = 1;
        for(int i = 0; i < 8; i++)
            straight = straight << 8 | 1;
    
    for (int i = 0; i < 8; i++){
        long long int temp = 255;
        temp = temp << (56 - 8 * i);
        if ((*board & temp) == temp){
            *rowColumn = i;
            return 1;
        }
    }
    
    for (int i = 0; i < 8; i++){
        long long int temp = straight;
        temp = temp << (7 - i);
        if ((*board & temp) == temp){
            *rowColumn = i;
            return 2;
        }
    }

    if ((*board & topleft) == topleft){
        *rowColumn = 0;
        return 3;
    }
    if ((*board & topright) == topright){
        *rowColumn = 1;
        return 3;
    }
    
    return 0;           

}