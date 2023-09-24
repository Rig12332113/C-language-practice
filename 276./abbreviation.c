#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main(void){
    char input[127];
    bool print;
    while(scanf("%s", input) != EOF){
        print = 1;
        if (strlen(input) == 2){
            if ((input[0] == 'o' && input[1] == 'f') || (input[0] == 'a' && input[1] == 't'))
                print = 0;
        }

        else if (strlen(input) == 3){
            if ((input[0] == 'a' && input[1] == 'n' && input[2] == 'd') || 
                (input[0] == 't' && input[1] == 'h' && input[2] == 'e') ||
                (input[0] == 'o' && input[1] == 'f' && input[2] == '.') ||
                (input[0] == 'a' && input[1] == 't' && input[2] == '.'))
                print = 0;
        }

        else if (strlen(input) == 4){
            if ((input[0] == 'a' && input[1] == 'n' && input[2] == 'd' && input[3] == '.') || 
                (input[0] == 't' && input[1] == 'h' && input[2] == 'e' && input[3] == '.'))
                print = 0;
        }

        if(print)
            printf("%c", toupper(*input));
        if (*(input + strlen(input) - 1) == '.')
            printf("\n");
    }
    return 0;
}