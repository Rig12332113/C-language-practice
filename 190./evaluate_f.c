#include"evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index){
    int maximum = 4 * (*(iptr[0])) - 6 * (*(iptr[0] + 1)), ans = 0;
    *index = 0;
    for(int i = 0; i < n; i++){
        ans = 4 * (*(iptr[i])) - 6 * (*(iptr[i] + 1)); 
        if (ans > maximum){
            maximum = ans;
            *index = i;
        }
    }
    return maximum;
}