#include <stdio.h>
int main(void){
    int ans = 0, temp = 0;
    while(scanf("%d", &temp) != EOF){
        ans += temp;
    }
    printf("%d", ans);
    return 0;
}