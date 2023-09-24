#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int main(void){
    long int a = 0, b = 0, c = 0;
    scanf("%ld%ld%ld", &a, &b, &c);
    long int ans[3] = {0};
    bool found = 0;

    //找第一個解
    if (c > 0){
        for(int i = 0; i > -100000 && !found; i--){
            if (i * i * i + a * i * i + b * i + c == 0){
                ans[0] = (-1) * i;
                found = 1;
            }
        }
    }
    else if(c < 0){
        for(int i = 0; i < 100000 && !found; i++){
            if (i * i * i + a * i * i + b * i + c == 0){
                ans[0] = (-1) * i;
                found = 1;
            }
        }
    }
    else{
        ans[0] = 0;
    }
    
    //除因式
    long int d = 0, f = 0;
    if (c != 0){
        d = a - ans[0];        
        f = c / ans[0];
    }
    else{
        d = a;
        f = b;
    }

    //求另外兩解
    ans[1] = (-1) * (-1 * d + sqrt (d * d - 4 * f)) / 2;
    ans[2] = (-1) * (-1 * d - sqrt (d * d - 4 * f)) / 2;

    //排序
    for(int i = 2; i > 0; i--){
        for(int j = 0; j < i; j++){
            long int temp = 0;
            if (ans[j] > ans[j+1]){
                temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        } 
    }
    
    printf("%ld %ld %ld\n", ans[0], ans[1], ans[2]);
    
    return 0;
}