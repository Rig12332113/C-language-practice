#include <stdio.h>
int main(void){
    int money = 0;
    while(scanf("%d", &money) == 1){
        int type[7];
        type[0] = money / 1000;
        money %= 1000;
        type[1] = money / 500;
        money %= 500;
        type[2] = money / 100;
        money %= 100;
        type[3] = money / 50;
        money %= 50;
        type[4] = money / 10;
        money %= 10;
        type[5] = money / 5;
        type[6] = money % 5;
        for(int i = 0; i < 7; i++){
            if (i == 6)
                printf("%d\n", type[6]);
            else
                printf("%d ", type[i]);
        }
    }

    return 0;
}