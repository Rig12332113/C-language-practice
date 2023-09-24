#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void){
    char string[1000];
    bool valid = 1;
    while(valid == 1){
        scanf("%s",string);
        if (string[0] == '-' && string[1] == '1')
            break;
        // 2的倍數
        if (string[strlen(string) - 1] == '0' ||
            string[strlen(string) - 1] == '2' ||
            string[strlen(string) - 1] == '4' ||
            string[strlen(string) - 1] == '6' ||
            string[strlen(string) - 1] == '8' )
            printf("yes ");
        else
            printf("no ");

        // 3的倍數
        int digit_sum = 0;
        for(int i = 0; i < strlen(string); i++)
            digit_sum += string[i] - '0';
        if (digit_sum % 3 == 0)
            printf("yes ");
        else
            printf("no ");
            
        // 5的倍數
        if (string[strlen(string) - 1] == '0' ||
            string[strlen(string) - 1] == '5' )
            printf("yes ");
        else
            printf("no ");

        // 11的倍數
        int odd_digit_sum = 0, even_digit_sum = 0;
        for(int i = 0; i < strlen(string); i++){
            if (i % 2 == 1)
                odd_digit_sum += string[i] - '0';
            else
                even_digit_sum += string[i] - '0';
        }
        if ((odd_digit_sum - even_digit_sum) % 11 == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}