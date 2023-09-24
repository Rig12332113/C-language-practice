#include<stdio.h>
#include<stdbool.h>
int main(){
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    bool valid = (a + b > c) && (b + c > a) && (c + a > b);
    printf("%d\n", valid);

    return 0;

}