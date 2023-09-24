#include<stdio.h>
#include<string.h>
int num = 0;
void find(char *check, char string[80000][100]){
    int len = strlen(check);
    int similar[80000] = {0};
    int size = 0;
    for(int i = 0; i < num; i++){
        if (strcmp(check, string[i]) == 0){
            //printf("case 1");
            printf(">%s\n", check);
            return;
        }
        int wrong = 0;
        if (len == strlen(string[i])){
            //printf("case 2");
            for(int j = 0; j < len && wrong < 2; j++)
                if(*(check + j) != *(string[i] + j)) 
                    wrong++;
            if (wrong < 2){
                similar[size] = i;
                size++;
            }
        }
        else if (len == strlen(string[i]) - 1){
            //printf("case 3");
            for(int j = 0; j <= len && wrong < 2; j++){
                if(!wrong){
                    if(*(check + j) != *(string[i] + j)) 
                        wrong++;
                }
                else{
                    if(*(check + j - 1) != *(string[i] + j)) 
                        wrong++;
                }
            }
            if (wrong < 2){
                similar[size] = i;
                size++;
            }
        }
        else if (len == strlen(string[i]) + 1){
            //printf("case 4");
            for(int j = 0; j <= len && wrong < 2; j++){
                if(!wrong){
                    if(*(check + j) != *(string[i] + j)) 
                        wrong++;
                }
                else{
                    if(*(check + j) != *(string[i] + j - 1)) 
                        wrong++;
                }
            }
            if (wrong < 2){
                similar[size] = i;
                size++;
            }
        }
    }
    if (size == 0)
        printf("!%s\n", check);
    else{
        printf("?");
        for(int j = 0; j < size; j++){
            if (j == size - 1)
                printf("%s\n", string[similar[j]]);
            else
                printf("%s ", string[similar[j]]);
        }
    }
}
int main(void){
    char string[80000][100];
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
        scanf("%s", string[i]);
    int check_num = 0;
    scanf("%d", &check_num);
    char check[100];
    for(int i = 0; i < check_num; i++){
        scanf("%s", check);
        find(check, string);
    }
    
    return 0;
}