#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int dicnum = 0;
    scanf("%d", &dicnum);
    char dictionary[200][50];
    for (int i = 0; i < dicnum; i++)
        scanf("%s", dictionary[i]);
    int qnum = 0;
    scanf("%d", &qnum);
    for (int i = 0; i < qnum; i++){
        int count = 0;
        char substring[50];
        scanf("%s", substring);
        for (int j = 0; j < dicnum; j++){
            char *find = strstr(dictionary[j], substring);
            if (find != NULL)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}