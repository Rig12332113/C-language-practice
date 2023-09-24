#include <stdio.h>
int main(void){
    int size_r = 0, size_c = 0, x = 0, y = 0;
    while(scanf("%d%d%d%d", &size_c, &size_r, &x, &y) == 4){
        int ini_x = x, ini_y = y;
        do{
            printf("%d %d\n", x, y);
            if (x == 0 && y > 0)
                y--;
            else if (y % 2 == 0 && x < size_c - 1)
                x++;
            else if ((y % 2 == 1 && x > 1) || (y == size_r - 1 && x > 0))
                x--;
            else
                y++;
        }while(x != ini_x || y != ini_y);
        printf("%d %d\n", x, y);
    } 
    return 0;
}