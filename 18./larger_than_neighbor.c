#include<stdio.h>
#include<stdbool.h>
int main(){
    int r = 0, c = 0;
    int m[100][100];
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &m[i][j]);
        }
    }
    bool x_max = 0, y_max = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if ((j == 0 && m[i][j] > m[i][j+1]) || (j == c - 1 && m[i][j] > m[i][j-1]))
                x_max = 1;
            else if ((j != 0 && j != c - 1 && m[i][j] > m[i][j+1] && m[i][j] > m[i][j-1]))
                x_max = 1;
            if ((i == 0 && m[i][j] > m[i+1][j]) || (i == r - 1 && m[i][j] > m[i-1][j]))
                y_max = 1;
            else if ((i != 0 && i != r - 1 && m[i][j] > m[i+1][j] && m[i][j] > m[i-1][j]))
                y_max = 1;
            if(x_max && y_max)
                printf("%d\n", m[i][j]);
            x_max = 0, y_max = 0;
        }
    }
    return 0;
}
/*
23 54 73 27 
35 14 0  6  
84 72 90 189
9  83 27 44
*/
