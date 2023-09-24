#include <stdio.h>
int find_devider(int a, int b){
    if (a == 0 || b == 0)
        return 1;
    while(a % b != 0 && b % a != 0){
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a > b ? b : a;
}
int main(void){
    int top ,bottom;
    while(scanf("%d%d", &top, &bottom) == 2){
        int max_devider = find_devider(top, bottom);
        printf("%d / %d\n", top / max_devider, bottom / max_devider);
    }

    return 0;
}