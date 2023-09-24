#include <stdio.h>
#include "setmatrix.h"
 
void processSetMatrix(int ***ptr) {
    int i = 0, j = 0, k = 0;
    while(*(ptr + i) != NULL){
        while(*(*(ptr + i) + j) != NULL){
            while(*(*(*(ptr + i) + j) + k) != 0){
                printf("%d ", *(*(*(ptr + i) + j) + k));
                k++;
            }
        j++;
        k = 0;
        }
    i++;
    j = 0;
    }
}