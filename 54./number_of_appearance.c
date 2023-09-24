#include<stdio.h>
int main(){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int a_digit[2], b_digit[7];
    a_digit[1] = a % 10;
    a_digit[0] = a / 10;
    for(int i = 6; i >= 0; i--){
        b_digit[i] = b % 10;
        b = b / 10;
    }
    int same = 0;
    for (int i = 0; i < 6; i++){
        if(a_digit[0] == b_digit[i]){
            if(a_digit[1] == b_digit[i+1])
                same++;
        }
    }
    printf("%d\n", same);
    return 0;
}