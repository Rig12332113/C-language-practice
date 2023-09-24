#include<stdio.h>
int multiplier(int ans, int next);
int main(void){
    int ans, next;
    scanf("%d", &ans);
    while(scanf("%d", &next) != EOF){
        if (ans % next == 0)
            continue;
        else
            ans = multiplier(ans, next);
    }
    printf("%d", ans);
    return 0;
}


int multiplier(int ans, int next){
    int small = ans < next ? ans : next;
    for (int i = small; i > 0; i--){
        if ((ans % i == 0) && (next % i == 0))
            return (ans / i) * (next / i) * i;
    }
}