#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(void){
    int line_num = 0, height = 0, width = 0;
    int paper[100][100] = {0};
    scanf("%d%d%d", &line_num, &height, &width);
    bool valid = 1;
    int line = 1;
    while(line <= line_num && valid){
        int point_num = 0, now_x = 0, now_y = 0;
        int point = 2;
        scanf("%d%d%d", &point_num, &now_x, &now_y);
        if (now_x < 0 || now_x >= width || now_y < 0 || now_y >= height){
            printf("\nERROR %d 1", line);
            valid = 0;
        }
        while(point <= point_num && valid){
            int next_x = 0, next_y = 0, type = 0;
            scanf("%d%d", &next_x, &next_y);
            if(now_x == next_x)
                type = 1;       //直線
            else if(now_y == next_y)
                type = 2;       //橫線
            else if(abs(now_x - next_x) == abs(now_y - next_y))
                type = 3;       //斜線
            else{
                printf("ERROR %d %d", line, point);
                valid = 0;
            }

            int i, j, m, n;
            switch(type){
                case 1:
                    i = now_y < next_y ? now_y : next_y;
                    j = now_y > next_y ? now_y : next_y;
                    while(i <= j){
                        paper[height - i - 1][now_x] = 1;
                        i++;
                    }
                    break;
                case 2:
                    i = now_x < next_x ? now_x : next_x;
                    j = now_x > next_x ? now_x : next_x;
                    while(i <= j){
                        paper[height - now_y - 1][i] = 1;
                        i++;
                    }
                    break;
                case 3:
                    i = now_x;
                    j = next_x;
                    m = now_y;
                    n = next_y; 
                    while(i < j && m < n){
                        paper[height - m -1][i] = 1;
                        i++;
                        m++;    
                    }//左下畫到右上
                    while(i < j && m > n){
                        paper[height - m - 1][i] = 1;
                        i++;
                        m--;
                    }//左上畫到右下
                    while(i >= j && m <= n){
                        paper[height - m -1][i] = 1;
                        i--;
                        m++;    
                    }//右下畫到左上
                    while(i >= j && m >= n){
                        paper[height - m -1][i] = 1;
                        i--;
                        m--;    
                    }//右上畫到左下
                    break;
            }
            now_x = next_x;
            now_y = next_y;

            point++;
        }
        line++;
    }


    for(int i = 0; i < height && valid; i++){
        for(int j = 0; j < width; j++){
            printf("%d", paper[i][j]);
        }
        printf("\n");
    }
    return 0;
}