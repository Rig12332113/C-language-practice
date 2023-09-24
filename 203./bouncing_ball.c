#include <stdio.h>
typedef struct ball
{
    int x, y, dx, dy;
} Ball;
int X, Y;
void move(Ball *b1, Ball *b2){
    int temp_x1, temp_y1, temp_x2, temp_y2;
    temp_x1 = b1->x + b1->dx;
    temp_y1 = b1->y + b1->dy;
    temp_x2 = b2->x + b2->dx;
    temp_y2 = b2->y + b2->dy;
    if (temp_x1 <= 0 || temp_x1 > X){
        b1->x = b1->x - b1->dx;
        b1->dx *= -1;
    }
    else
        b1->x = temp_x1; 
    if (temp_y1 <= 0 || temp_y1 > Y){
        b1->y = b1->y - b1->dy;
        b1->dy *= -1;
    }
    else
        b1->y = temp_y1;
    if (temp_x2 <= 0 || temp_x2 > X){
        b2->x = b2->x - b2->dx;
        b2->dx *= -1;
    }
    else
        b2->x = temp_x2;
    if (temp_y2 <= 0 || temp_y2 > Y){
        b2->y = b2->y - b2->dy;
        b2->dy *= -1;
    }
    else
        b2->y = temp_y2;

    if (b1->x == b2->x && b1->y == b2->y){
        if (b1->dx == b2->dx){
            b1->dy *= -1;
            b2->dy *= -1;
        }
        else if (b1->dy == b2->dy){
            b1->dx *= -1;
            b2->dx *= -1;
        }
        else{
            b1->dx *= -1;
            b1->dy *= -1;
            b2->dx *= -1;
            b2->dy *= -1;
        }
    }
}
int main(void){
    Ball B1;
    Ball B2;
    Ball *b1 = &B1;
    Ball *b2 = &B2;
    int time;
    scanf("%d%d", &X, &Y);
    scanf("%d%d", &b1->x, &b1->y);
    scanf("%d%d", &b2->x, &b2->y);
    scanf("%d%d", &b1->dx, &b1->dy);
    scanf("%d%d", &b2->dx, &b2->dy);
    scanf("%d", &time);
    while(time > 0){
        move(b1, b2);
        //printf("(%d,%d) (%d,%d)\n", b1->x, b1->y, b2->x, b2->y);
        time--;
    }
    printf("%d\n%d\n%d\n%d\n", b1->x, b1->y, b2->x, b2->y);
    return 0;
}