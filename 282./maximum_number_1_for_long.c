#include<stdio.h>
int main(void){
    long int number;
    while(scanf("%ld", &number) != EOF){
        int binary_num[64] = {0};
        int i = 0;
        while (number >= 1){
            binary_num[i] = number % 2;
            number /= 2;
            i++;
        }
        int count = 0;
        for(int j = 0; j < 64; j++)
            if (binary_num[j] == 1)
                count++;
        printf("%d\n", count);
        
    }
    return 0;
}