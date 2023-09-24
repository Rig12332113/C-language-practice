#include<stdio.h>
#include<stdbool.h>
typedef struct circle
{
    int x;
    int y;
    int radius;
} Circle;

int main(void){
    int cases = 0, num = 0;
    scanf("%d", &cases);
    int ans[100];
    while(num < cases){
        Circle c1;
        Circle c2;
        Circle c3;
        scanf("%d%d%d", &c1.x, &c1.y, &c1.radius);
        scanf("%d%d%d", &c2.x, &c2.y, &c2.radius);
        scanf("%d%d%d", &c3.x, &c3.y, &c3.radius);
        int type[4] = {0};
        for(int i = -1 * c1.radius; i <= c1.radius; i++)
            for(int j = -1 * c1.radius; j <= c1.radius; j++){
                long long int temp_x = c1.x + i;
                long long int temp_y = c1.y + j;
                int in = 0;
                bool valid = 0;
                if ((temp_x - c1.x) * (temp_x - c1.x) + (temp_y - c1.y) * (temp_y - c1.y) 
                    <= c1.radius * c1.radius){
                    in++;
                    valid = 1;
                }
                if ((temp_x - c2.x) * (temp_x - c2.x) + (temp_y - c2.y) * (temp_y - c2.y) 
                    <= c2.radius * c2.radius)
                    in++;
                if ((temp_x - c3.x) * (temp_x - c3.x) + (temp_y - c3.y) * (temp_y - c3.y) 
                    <= c3.radius * c3.radius)
                    in++;
                if (valid)
                    type[in]++;
            }
        for(int i = -1 * c2.radius; i <= c2.radius; i++)
            for(int j = -1 * c2.radius; j <= c2.radius; j++){
                long long int temp_x = c2.x + i;
                long long int temp_y = c2.y + j;
                int in = 0;
                bool valid = 0;
                if ((temp_x - c1.x) * (temp_x - c1.x) + (temp_y - c1.y) * (temp_y - c1.y) 
                    <= c1.radius * c1.radius)
                    in++;
                if ((temp_x - c2.x) * (temp_x - c2.x) + (temp_y - c2.y) * (temp_y - c2.y) 
                    <= c2.radius * c2.radius){
                    in++;
                    valid = 1;
                }
                if ((temp_x - c3.x) * (temp_x - c3.x) + (temp_y - c3.y) * (temp_y - c3.y) 
                    <= c3.radius * c3.radius)
                    in++;
                if (valid)
                    type[in]++;
            }
        for(int i = -1 * c3.radius; i <= c3.radius; i++)
            for(int j = -1 * c3.radius; j <= c3.radius; j++){
                long long int temp_x = c3.x + i;
                long long int temp_y = c3.y + j;
                int in = 0;
                bool valid = 0;
                if ((temp_x - c1.x) * (temp_x - c1.x) + (temp_y - c1.y) * (temp_y - c1.y) 
                    <= c1.radius * c1.radius)
                    in++;
                if ((temp_x - c2.x) * (temp_x - c2.x) + (temp_y - c2.y) * (temp_y - c2.y) 
                    <= c2.radius * c2.radius)
                    in++;
                if ((temp_x - c3.x) * (temp_x - c3.x) + (temp_y - c3.y) * (temp_y - c3.y) 
                    <= c3.radius * c3.radius){
                    in++;
                    valid = 1;
                }
                if (valid)
                    type[in]++;
            }
        ans[num] = type[1] + type[3] / 3;
        num++;
    }
    for(int i = 0; i < cases; i++)
        printf("%d\n", ans[i]);
    return 0;
}