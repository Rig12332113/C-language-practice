#include <stdio.h>
#include "fill_array.h"
void fill_array(int *ptr[], int n){
    for(int i = 0; i < ptr[n-1] - ptr[0]; i++){
        *(ptr[0] + i) = -1;
    }
    for(int i = 0; i < n; i++)
        *ptr[i] = i;
    int arr[10000];
    int num = 0;
    for(int i = 0; i <= ptr[n-1] - ptr[0]; i++){
        if (*(ptr[0] + i) >= 0){
            arr[num] = *(ptr[0] + i);
            num++;
        }
    }
    num = -1;
    for(int i = 0; i < ptr[n-1] - ptr[0]; i++){
        if (*(ptr[0] + i) >= 0)
            num++;
        else 
            *(ptr[0] + i) = arr[num] + arr[num+1];
    }
}