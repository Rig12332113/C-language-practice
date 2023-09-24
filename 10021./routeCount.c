#include <stdio.h>
#include <stdlib.h>
int main(void){
    int row = 0, column = 0;
    while(scanf("%d%d", &row, &column) == 2){
        int **map = (int **)malloc(sizeof(int *) * row);
        for(int i = 0; i < row; i++){
            map[i] = (int *)malloc(sizeof(int) * column);
            for(int j = 0; j < column; j++){
                scanf("%d", &map[i][j]);
            }
        }
        unsigned long long int **routenum = (unsigned long long int **)malloc(sizeof(unsigned long long int *) * row);
        for(int i = 0; i < row; i++){
            routenum[i] = (unsigned long long int *)malloc(sizeof(unsigned long long int) * column);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if (map[i][j] == 1)
                    routenum[i][j] = 0;
                else if (i == 0 && j == 0)
                    routenum[i][j] = 1;
                else if (i == 0)
                    routenum[i][j] = routenum[i][j - 1];
                else if (j == 0)
                    routenum[i][j] = routenum[i - 1][j];
                else
                    routenum[i][j] = routenum[i - 1][j] + routenum[i][j - 1];
            }
        }
        free(map);
        /*for(int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (j == column - 1)
                    printf("%llu\n", routenum[i][j]);
                else
                    printf("%llu ", routenum[i][j]);
            }
        }*/
        printf("%llu\n", routenum[row - 1][column - 1]);
        free(routenum);
    }
    return 0;
}