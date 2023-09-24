#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    if (!(num % 15) && num % 7)
        printf("0\n");
    else
        printf("1\n");
}