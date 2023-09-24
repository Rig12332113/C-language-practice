#include<stdio.h>
#include<stdbool.h>
int main(void){
    int count = 0;
    bool valid = 0, doublespace = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if (c == '.')
            valid = 1;
        else if ((c == '\n' || c == '\0') && valid){
            count++;
            valid = 0;
        }
        else if (c == ' ' && valid){
            valid = 0;
            doublespace = 1;
        }
        else if (c == ' '  && doublespace){
            count++;
            doublespace = 0;
        }
        else{
            valid = 0;
            doublespace = 0;
        }
    }
    printf("%d\n", count);
    return 0;
}