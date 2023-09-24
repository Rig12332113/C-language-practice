#include<stdio.h>
int square(int num){
    if (num == 1)
        return 1;
    else
        return (num * num + square(num - 1));
}
int main(void){
    int num = 0;
    scanf("%d", &num);
    printf("%d", square(num));
    return 0;
}