#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);
        char number[1024];
        int index = 0; 
        for (int i = 0; i < n; i++) {
            char c = s[i];    
            if (isdigit(c) == 1){
                number[index] = c;
                index++;
            }
            else if (isdigit(c) == 0 && index != 0){
                printf("%d\n", atoi(number));
                memset(number, ' ', index);
                index = 0;
            }
        }
        if (index != 0)
            printf("%d\n", atoi(number));
    }
    memset(s, ' ', strlen(s));
    return 0;
}