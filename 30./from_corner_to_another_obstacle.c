#include<stdio.h>
int count(int map[12][12], int row, int column, int y, int x){
    if (map[y][x] == 0)
        return 0;
    else if (x == column - 1 && y == 0)
        return 1;
    else if (x == column - 1)
        return count(map, row, column, y - 1, x);
    else if (y == 0)
        return count(map, row, column, y, x + 1);
    else
        return count(map, row, column, y - 1, x)
             + count(map, row, column, y, x + 1); 
}
int main(void){
    int row = 0, column = 0;
    scanf("%d%d", &row, &column);
    int map[12][12] = {0};
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            scanf("%d", &map[i][j]);
    printf("%d", count(map, row, column, row - 1, 0));      

    return 0;
}