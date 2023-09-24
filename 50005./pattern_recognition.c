#include<stdio.h>
#include<stdlib.h>
int main(void){
    //輸入
    int big = 0, small = 0, dif_num = 0, dif_sum = 0;
    scanf("%d%d%d%d", &big, &small, &dif_num, &dif_sum);
    int graph[10][10];
    for(int i = 0; i < big; i++)
        for(int j = 0; j < big; j++)
            scanf("%d", &graph[i][j]);
    int pattern[10][10];
    int sum_p = 0;
    for(int i = 0; i < small; i++)
        for(int j = 0; j < small; j++){
            scanf("%d", &pattern[i][j]);
            sum_p += pattern[i][j]; 
        }
    //判斷
    int same_i = -1, same_j = -1;
    for(int i = 0; i <= big - small; i++){
        for(int j = 0; j <= big - small; j++){
            int count = 0, sum_g = 0;
            for(int m = 0; m < small; m++){
                for(int n = 0; n < small; n++){
                    sum_g += graph[i+m][j+n];
                    if (graph[i+m][j+n] == pattern[m][n])
                        count++;
                }
            }
            if (small * small - count <= dif_num && abs(sum_p - sum_g) <= dif_sum){
                same_i = i;
                same_j = j;
            }           
        }
    }
    printf("%d %d", same_i, same_j);
    return 0;
}