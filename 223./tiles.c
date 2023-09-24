#include <stdio.h>
void mapping(int cen_x, int cen_y, int type, int loss){
    if (loss == 1)
        printf("%d %d %d\n", type, cen_x, cen_y);
    else{
        switch(type){
            case 1:
                mapping(cen_x, cen_y, 1, loss / 2);
                mapping(cen_x - loss / 2, cen_y + loss / 2, 4, loss / 2);
                mapping(cen_x - loss / 2, cen_y - loss / 2, 1, loss / 2);
                mapping(cen_x + loss / 2, cen_y - loss / 2, 2, loss / 2);
                break;
            case 2:
                mapping(cen_x, cen_y, 2, loss / 2);
                mapping(cen_x + loss / 2, cen_y + loss / 2, 3, loss / 2);
                mapping(cen_x + loss / 2, cen_y - loss / 2, 2, loss / 2);
                mapping(cen_x - loss / 2, cen_y - loss / 2, 1, loss / 2);
                break;
            case 3:
                mapping(cen_x, cen_y, 3, loss / 2);
                mapping(cen_x - loss / 2, cen_y + loss / 2, 4, loss / 2);
                mapping(cen_x + loss / 2, cen_y + loss / 2, 3, loss / 2);
                mapping(cen_x + loss / 2, cen_y - loss / 2, 2, loss / 2);
                break;
            case 4:
                mapping(cen_x, cen_y, 4, loss / 2);
                mapping(cen_x + loss / 2, cen_y + loss / 2, 3, loss / 2);
                mapping(cen_x - loss / 2, cen_y + loss / 2, 4, loss / 2);
                mapping(cen_x - loss / 2, cen_y - loss / 2, 1, loss / 2);
                break;
        }
    }
}

int main(void){
    int big = 0, small = 0;
    scanf("%d%d", &big, &small);
    int cen_x = big / 2;
    int cen_y = big / 2;
    while(big != small * 2){
        mapping(cen_x, cen_y, 1, big / 2);
        big /= 2;
        cen_x += big / 2;
        cen_y += big / 2;
    }
    mapping(cen_x, cen_y, 1, big / 2);
    return 0;
}