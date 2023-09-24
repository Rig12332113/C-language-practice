#include <stdio.h>
int main(void){
    int M = 0;
    scanf("%d", &M);
    int N = 0;
    N = (M > 0) && (M % 2 == 0) && (M > 10000 || M < 1000);
    printf("%d", N);
    return 0;
}