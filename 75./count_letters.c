#include<stdio.h>
#include<string.h>
int main(void){
    char string[100];
    int letter[26] = {0};
    scanf("%s", string);
    for(int i = 0; i < strlen(string); i++){
        for (int j = 0; j < 26; j++)
            if ((int)string[i] == (int)('A' + j) || (int)string[i] == (int)('a' + j))
                letter[j]++;
    }
    for(int i = 0; i < 26; i++)
        printf("%d\n", letter[i]);
    return 0;
}