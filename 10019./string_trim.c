#include<stdio.h>
#include<ctype.h>
#include<string.h>
void trim(char *string);
int main(void){
    char c;
    int num = 0;
    char string[100];
    while(scanf("%c", &c) != EOF){
        *(string + num) = c;
        num++;
    }
    *(string + num) = '\0';
    trim(string); 
    return 0;
}

void trim(char *string){
    char *ans = string;
    for(int i = strlen(string) - 1; i > 0; i--){
        if (isspace(*(string + i)))
            *(ans + i) = '\0';
        else
            break;
    }
    for(int i = 0; i < strlen(string); i++)
        if (isspace(*(string + i)))
            ans = string + i + 1;
        else
            break;
    printf("%s\n", ans);
}
