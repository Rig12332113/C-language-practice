#include<stdio.h>
int main(){
    int num = 0, power = 0, ans = 1;
    scanf("%d %d", &num, &power);
    while(power > 0){
        ans = ans * num;
        power--;
    }
    printf("%d\n", ans);
    return 0;
}