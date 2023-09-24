#include <stdio.h>
int main(void){
    int N = 0, M = 0;
    scanf("%d%d", &N, &M);
    int cmd = 0, x = 0, y = 0, valid = 1;
    while(scanf("%d", &cmd) != EOF){
        if (valid)
            printf("%d\n%d\n", x, y);
        switch(cmd % 5){
            case 0:
                valid = 0;
                break;
            case 1:
                if (x > N - cmd - 1){
                    valid = 0;
                    break;
                }
                x += cmd;
                valid = 1;
                break;
            case 2:
                if (x < cmd){
                    valid = 0;
                    break;
                }
                x -= cmd;
                valid = 1;
                break;
            case 3:
                if (y > M - cmd - 1){
                    valid = 0;
                    break;
                }
                y += cmd;
                valid = 1;
                break;
            case 4:
                if (y < cmd){
                    valid = 0;
                    break;
                }
                y -= cmd;
                valid = 1;
                break;
        }
    }
    if (valid)
        printf("%d\n%d\n", x, y);
    return 0;
}