#include <stdio.h>
#include <stdlib.h>
int main(void){
    int row  = 0, column = 0;
    while (scanf("%d%d", &row, &column) == 2){
        int *matrix = (int *)malloc(sizeof(int) * row * column);
        int *row_sum = (int *)malloc(sizeof(int) * row);    
        int *column_sum = (int *)malloc(sizeof(int) * column);
        for (int i = 0; i < row; i++)
            scanf("%d", &row_sum[i]);
        for (int i = 0; i < column; i++)
            scanf("%d", &column_sum[i]);
        for(int i = 0; i < row * column; i++)
            matrix[i] = i + 1;
        
        int solvable = 0;
        solvable = move(matrix, 0, row * column, row_sum, column_sum, row, column);
        if(solvable){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    if (j == column - 1)
                        printf("%d\n", matrix[i * column + j]);
                    else
                        printf("%d ", matrix[i * column + j]);
                }
            }
        }
        else
            printf("no solution\n");
        free(matrix);
        free(row_sum);
        free(column_sum);
    }
    return 0;
}