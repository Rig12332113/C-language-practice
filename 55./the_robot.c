#include <stdio.h>
int M = 0, N = 0;
typedef struct robot
{
    int x, y, e, n, f;
}Robot;
int main(void){
    scanf("%d%d", &M, &N);
    Robot r1, r2;
    Robot *R1 = &r1, *R2 = &r2;
    scanf("%d%d%d%d%d", &r1.x, &r1.y, &r1.e, &r1.n, &r1.f);
    scanf("%d%d%d%d%d", &r2.x, &r2.y, &r2.e, &r2.n, &r2.f);
    int time = 0;
    while(time < r1.f || time < r2.f){
        if (time < r1.f){
            if (time % (R1->e + R1->n) < R1->n){
                R1->y += 1;
                if (R1->y == N)
                    R1->y = 0;
            }
            else{
                R1->x += 1;
                if (R1->x == M)
                    R1->x = 0;
            }
        }
        //printf("%d %d, ", r1.x, r1.y);
        if (time < r2.f){
            if (time % (R2->e + R2->n) < R2->e){
                R2->x += 1;
                if (R2->x  == M)
                    R2->x  = 0;
            }
            else{
                R2->y += 1;
                if (R2->y == N)
                    R2->y = 0;
            } 
        }
        //printf("%d %d\n", r2.x, r2.y);
        if (r1.x == r2.x && r1.y == r2.y){
            printf("robots explode at time %d", time + 1);
            return 0;
        }
        time++;
    }
    printf("robots will not explode");
    return 0;
}