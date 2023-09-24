#include<stdio.h>
int count(int row, int column){
    if (row == 1 || column == 1)
        return 1;
    else
        return count(row - 1, column) + count(row, column - 1);
}
int main(void){
    int row = 0, column = 0;
    scanf("%d%d", &row, &column);
    printf("%d", count(row, column));
    return 0;
}