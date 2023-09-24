#include<stdio.h>
int main(void){
    int top = 0, bottom = 0;
    scanf("%d%d", &top, &bottom);
    printf("%d\n", (top + bottom) * (bottom - top + 1) / 2);
    printf("%d\n", 3 * bottom - top - 2);
    return 0;
}