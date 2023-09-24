#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    double A[16][16] = {{0}};
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            scanf("%lf", &A[i][j]);
    
    double x[16], temp[16];
    for(int i = 0; i < num; i++){
        scanf("%lf", &x[i]);
        temp[i] = x[i];
    }

    double y[16];
    for(int i = num - 1; i >= 0; i--){  
        for(int j = num - 1; j > i; j--){
            temp[i] -= A[i][j] * y[j];
        }
        y[i] = temp[i] / A[i][i];
    }
    for (int i = 0; i < num; i++)
        printf("%lf\n", y[i]);
    
    return 0;
}