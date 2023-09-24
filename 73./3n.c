#include<stdio.h>
int main(){
    int num = 0;
    int a = 0, b = 0, c = 0;  
    scanf("%d", &num);
    while(num > 0){
        int number = 0;
        scanf("%d", &number);
        if (number % 3 == 0)
            a++;
        else if(number % 3 == 1)
            b++;
        else
            c++;
        num--;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}