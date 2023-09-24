#include "subset.h"
int subset(int numbers[], int n, int K, int S){
    if (n < 0)
        return 0;
    else if (K == 0 && S == 0){
        //printf("%d %d %d case1\n",n ,K, S);
        return 1;
    }
    else if(K < 0 || S <= 0 || n < S){
        //printf("%d %d %d case2\n",n ,K, S);
        return 0;
    }
    else{
        //printf("%d %d %d case3\n",n ,K, S);
        return subset(numbers, n - 1, K - numbers[n-1], S - 1) || subset(numbers, n - 1, K, S);
    }
}