#include<stdio.h>
int main(){
    int r = 0, c = 0;
    scanf("%d%d", &r, &c);
    int sum[100], list[100][100];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &list[i][j]);
        }
    }
    for(int j = 0; j < c; j++){
        sum[j] = 0;
        for(int i = 0; i < r; i++){
            sum[j] += list[i][j];
        }
        printf("%d\n", sum[j] / r);     
    }

    return 0;
}