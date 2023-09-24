#include<stdio.h>
int main(){
    int a = 0, b = 0;
    int a_digit[4], b_digit[4];
    int allright = 0, partright = 0;
    scanf("%d %d", &a, &b);
    for(int i = 3; i >= 0; i--){
        a_digit[i] = a % 10;
        a = a / 10;
        b_digit[i] = b % 10;
        b = b / 10;
    }
    for(int i = 0; i < 4; i++){
        if(a_digit[i] == b_digit[i])
            allright++;
        for(int j = 0; j < 4; j++){
            if(a_digit[i] == b_digit[j])
                partright++;
        }
    }
    printf("%dA%dB\n", allright, partright - allright);

    return 0;
}