#include <stdio.h>
#include <string.h>
int main(void){
    int limit = 0;
    char buffer[257] = {'\0'};
    scanf("%d", &limit);
    int word_num = 0, digit = 0;
    char data[128][257] = {{'\0'}};
    while(scanf("%s", buffer) != EOF){
        int temp = strlen(buffer);
        if (digit + word_num + temp <= limit){
            strcpy(data[word_num], buffer);
            digit += temp;
            word_num++;
        }
        else{
            for(int i = 0; i < word_num; i++){
                if (i == word_num - 1){
                    printf("%s\n", data[i]);
                }
                else{
                    printf("%s", data[i]);
                    int space_devide = (limit - digit) % (word_num - 1);
                    int space_num = i < space_devide ? (limit - digit) / (word_num - 1) + 1: (limit - digit) / (word_num - 1);
                    for(int j = 0; j < space_num; j++)
                        printf(" ");
                }
            }
            strcpy(data[0], buffer);
            word_num = 1;
            digit = strlen(buffer);
        }
    }
    for(int i = 0; i < word_num; i++){
        if (word_num == 1){
            for(int j = 0; j < (limit - digit); j++)
                printf(" ");
            printf("%s\n", data[0]);
        }
        else if (i == word_num - 1){
            printf("%s\n", data[i]);
        }
        else{
            printf("%s", data[i]);
            int space_devide = (limit - digit) % (word_num - 1);
            int space_num = i < space_devide ? (limit - digit) / (word_num - 1) + 1: (limit - digit) / (word_num - 1);
            for(int j = 0; j < space_num; j++)
                printf(" ");
        }
    }
    return 0;
}