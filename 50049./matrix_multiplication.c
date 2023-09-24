#include<stdio.h>
void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result){
    int a[1000][1000] = {{0}}, b[1000][1000] = {{0}};
    for(int i = 0; i < N; i++)
        a[*(ptrA[1] + i)][*(ptrA[2] + i)] = *(ptrA[0] + i);
    for(int i = 0; i < M; i++)
        b[*(ptrB[1] + i)][*(ptrB[2] + i)] = *(ptrB[0] + i); 
    for (int i = 0; i < S; i++)
        for(int m = 0; m < S; m++)
            for (int n = 0; n < S; n++)
                if (a[i][n] != 0 && b[n][m] != 0)
                    result[i * S + m] += a[i][n] * b[n][m];
    /*
    for (int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            if (j == S - 1)
                printf("%d\n", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
    }
    for (int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            if (j == S - 1)
                printf("%d\n", b[i][j]);
            else
                printf("%d ", b[i][j]);
        }
    }
    */

}