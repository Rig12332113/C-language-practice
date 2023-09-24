#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
    char input[100];
    scanf("%s", input);
    int digit = 0, alphabet = 0, vowel = 0;
    for(int i = 0; i < strlen(input); i++){
        if(isdigit(input[i]))
            digit++;
        else if(isalpha(input[i]))
            alphabet++;
        if(input[i] == 'A' || input[i] == 'a' 
                || input[i] == 'E' || input[i] == 'e'
                || input[i] == 'I' || input[i] == 'i'
                || input[i] == 'O' || input[i] == 'o'
                || input[i] == 'U' || input[i] == 'u')
            vowel++;
    }
    printf("%d %d %d %d\n", digit, alphabet, vowel, alphabet - vowel);
    
    return 0;
}