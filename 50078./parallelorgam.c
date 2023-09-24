#include<stdio.h>
#include<stdlib.h>

int main(void){
    int p1x, p1y, p2x, p2y, p3x, p3y;
    scanf("%d%d%d%d%d%d", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
    printf("%d\n", p2x + p3x - p1x);
    printf("%d\n", p2y + p3y - p1y);
    printf("%d\n", p3x + p1x - p2x);
    printf("%d\n", p3y + p1y - p2y);
    printf("%d\n", p2x + p1x - p3x);
    printf("%d\n", p2y + p1y - p3y);
    return 0;
}