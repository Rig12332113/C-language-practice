#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int x[3] = {0}, y[3] = {0};
int judge(int px, int py){
    for(int i = 0; i < 3; i++)
        if (px == x[i] && py == y[i])
            return 1;
    double v1x = x[0] - px;
    double v1y = y[0] - py;
    double v2x = x[1] - px;
    double v2y = y[1] - py;
    double v3x = x[2] - px;
    double v3y = y[2] - py;
    double angle1 = acos((v1x * v2x + v1y * v2y) / sqrt((v1x * v1x + v1y * v1y) * (v2x * v2x + v2y * v2y)));
    double angle2 = acos((v2x * v3x + v2y * v3y) / sqrt((v2x * v2x + v2y * v2y) * (v3x * v3x + v3y * v3y)));
    double angle3 = acos((v3x * v1x + v3y * v1y) / sqrt((v3x * v3x + v3y * v3y) * (v1x * v1x + v1y * v1y)));
    //printf("%f, %f (%d, %d)\n", angle1, angle2, px, py);
    if ((angle1 + angle2 > PI) && (angle2 + angle3 > PI) && (angle3 + angle1 > PI))
        return 1;
    else 
        return 0;
}
int main(void){
    scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
    int max_x = x[0], min_x = x[0], max_y = y[0], min_y = y[0];
    for(int i = 1; i < 3; i++){
        if (x[i] > max_x)
            max_x = x[i];
        if (x[i] < min_x)
            min_x = x[i];
        if (y[i] > max_y)
            max_y = y[i];
        if (y[i] < min_y)
            min_y = y[i];
    }
    int count = 0;
    for(int i = 0; i <= (max_x - min_x) / 100; i++)
        for(int j = 0; j <= (max_y - min_y) / 100; j++){
            int in[101][101] = {0};
            for(int m = 0; m < 101; m++){
                for(int n = 0; n < 101; n++){
                    in[100 - n][m] = judge(i * 100 + min_x + m, j * 100 + min_y + n);
                }
            }
            for(int m = 0; m < 100; m++){
                for(int n = 0; n < 100; n++){
                    if (in[100 - n][m] == 1 && in[100 - n - 1][m] == 1 && in[100 - n][m + 1] == 1 && in[100 - n - 1][m + 1] == 1){
                        //printf("%d, %d\n",i * 100 + min_x + m, j * 100 + min_y + n);
                        count++;
                    }
                }
            }
        }
    /*for(int i = 0; i <= max_y - min_y; i++)
        for(int j = 0; j <= max_x - min_x; j++){
            if (j == max_x - min_x)
                printf("%d\n", in[i][j]);
            else
                printf("%d ", in[i][j]);
        }
    */
    printf("%d", count);
    return 0;
}