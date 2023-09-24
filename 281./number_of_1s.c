#include<stdio.h>
int main(void){
    int number, count;
    while (scanf("%d", &number) != EOF){
        count = 0;
        while (number >= 2){
            if (number % 2 == 1)
                count++;
            number /= 2;
        }
        printf("%d\n", count + 1);
        //printf("%d", number);

    }
    return 0;
}