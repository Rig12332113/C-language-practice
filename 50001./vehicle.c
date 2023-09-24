#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int p, q, r, s;
    scanf("%d%d%d%d", &p, &q, &r, &s);
    int x, y, F;
    scanf("%d%d%d", &x, &y, &F);
    int dir = 0, gold = 0;
    bool transport = 1; 
    while(F >= 0){
        if(x == p && y == q && transport){
            x = r;
            y = s;
            transport = 0;
            if(F == 0)
                break;
            else
                continue;
        }
        else if(x == r && y == s && transport){
            x = p;
            y = q;
            transport = 0;
            if(F == 0)
                break;
            else
                continue;
        }
        else if(F > 0){
            if(transport)
                gold += (abs(c * x + d * y)) % e;
            dir = (abs(a * x + b * y)) % 4;
            switch(dir){
                case 0:
                    y++;        break;
                case 1:
                    x++;        break;
                case 2:
                    y--;        break;
                case 3:
                    x--;        break;
            }
            transport = 1;
            F--;
        }
        else
            break;
    }
    if(transport)
        gold += (c * x + d * y) % e;
    printf("%d\n", gold);
    printf("%d %d\n", x, y);
    return 0;
}