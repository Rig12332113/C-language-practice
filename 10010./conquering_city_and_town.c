#include <stdio.h>
#include <stdlib.h>
int main(void){
    int row = 0, column = 0;
    scanf("%d%d", &column, &row);
    int cmdnum = 0;
    scanf("%d", &cmdnum);
    int *field = (int *)malloc(sizeof(int) * row * column);
    for(int i = 0; i < row * column; i++)
        field[i] = 1;
    for (int i = 0; i < cmdnum; i++){
        int count = 0;
        int lx = 0, ly = 0, rx = 0, ry = 0;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        int *answer = (int *)malloc(sizeof(int) * row * column);
        for (int j = lx - 1; j <= rx - 1; j++){
            for (int k = ly - 1; k <= ry - 1; k++){
                if (field[column * k + j] == 1){
                    answer[count] = column * k + j;
                    count++;
                    field[column * k + j] = 0;
                }
            }
        }
        printf("%d", count);
        for (int j = 0; j < count; j++){
            printf(" (%d, %d)", answer[j] % column + 1, answer[j] / column + 1);
        }
        printf("\n");
        free(answer);
    }
    free(field);
    return 0;
}