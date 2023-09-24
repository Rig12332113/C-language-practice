#include<stdio.h>
#include"intersection.h"
#include"intersection.c"
int main(){
    int map[100][100] = {{0}}, result[4];
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            scanf("%d", &map[i][j]);
    intersection(map, result);
    for(int i = 0; i < 4; i++)
        printf("%d\n", result[i]);
    return 0;
}