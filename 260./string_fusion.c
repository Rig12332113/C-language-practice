#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(void){
    char ans[127], string[127];
    while(scanf("%s", string) != EOF){
        int count = 0;
        int length = strlen(ans) < strlen(string) ? strlen(ans) : strlen(string);
        for(int i = 1; i <= length; i++){
            bool valid = 0;
            for(int j = 0; j < i; j++){ 
                if(*(ans + strlen(ans) - i + j) == *(string + j))
                    valid = 1;
                else{
                    valid = 0;
                    break;
                }
            }
            if(valid)
                count = i;
        }
        strcat(ans, string + count);
    }
    printf("%s\n", ans);
    return 0;
}