#include <stdio.h>
#include <string.h>
int size = 0;
char dataset[1000000];
void replace(char *from, char *to){
    for(int i = 0; i < size; i++){
        if (dataset[i] == *from)
            dataset[i] = *to;
    }
}
void moveout(char *input){
    for(int i = 0; i < size; i++){
        if (dataset[i] == *input){
            char temp[1000000];
            strcpy(temp, dataset + i + 1);
            strcpy(dataset + i, temp);
            i -= 1;
            size--;
        }
    }
}
void addhead(char *input){
    char temp[1000000];
    strcpy(temp, dataset);
    strcpy(dataset + 1, temp);
    dataset[0] = *input;
    size++;
}
void addtail(char *input){
    dataset[size] = *input;
    size++;
}
int main(void){
    scanf("%s", dataset);
    size = strlen(dataset);
    char cmd[30];
    int valid = 1;
    while(scanf("%s", cmd) != EOF && strcmp(cmd, "end") != 0){
        if (strcmp(cmd, "replace") == 0){
            //printf("1");
            char from[2], to[2];
            scanf("%s%s", from, to);
            replace(from, to);
        }
        else if (strcmp(cmd, "remove") == 0){
            //printf("2");
            char input[2];
            scanf("%s", input);
            moveout(input);
        }
        else if (strcmp(cmd, "addhead") == 0){
            //printf("3");
            char input[2];
            scanf("%s", input);
            addhead(input);
        }
        else if (strcmp(cmd, "addtail") == 0){
            //printf("4");
            char input[2];
            scanf("%s", input);
            addtail(input);
        }
        else{
            printf("invalid command %s", cmd);
            valid = 0;
            break;
        }
    }
    if (valid)
        printf("%s", dataset);
    return 0;
}