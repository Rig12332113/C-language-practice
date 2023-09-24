#include <stdio.h>
#include <stdlib.h>
int check_row(int *matrix, int *row_sum, int row, int column){
    int correct = 1;
    for(int i = 0; i < row && correct; i++){
        int sum = 0;
        for(int j = 0; j < column; j++)
            sum += matrix[i * column + j];
        if (sum != row_sum[i])
            correct = 0;
        //printf("check row %d : %d", i , correct);
    }
    return correct;
}
int check_column(int *matrix, int *column_sum, int row, int column){
    int correct = 1;
    for(int i = 0; i < column && correct; i++){
        int sum = 0;
        for(int j = 0; j < row; j++)
            sum += matrix[j * column + i];
        if (sum != column_sum[i])
            correct = 0;
        //printf("check column %d : %d", i , correct);
    }
    return correct;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int move(int *matrix,int index, int size, int *row_sum, int *column_sum, int row, int column){
    int correct = 0;
    if (size == 1){
        return check_row(matrix, row_sum, row, column) && check_column(matrix, column_sum, row, column);
    }
    else{
        for(int i = 0; i < size && !correct; i++){
            swap(matrix + index, matrix + index + i);
            correct = move(matrix, index + 1, size - 1, row_sum, column_sum, row, column);
            if (!correct)
                swap(matrix + index, matrix + index + i);
        }
        return correct;
    }
}
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