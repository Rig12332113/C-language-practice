#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char dataset[50000];
int size = 0;
void insert(char opr2[6], char data){
    if (strcmp(opr2, "left") == 0){
        for(int i = size; i > 0; i--)
            dataset[i] = dataset[i - 1];
        dataset[0] = data;
    }
    else if (strcmp(opr2, "right") == 0){
        dataset[size] = data;
    }
    else{
        int place = atoi(opr2);
        for(int i = size; i >= place; i--){
            dataset[i] = dataset[i - 1];
        }
        dataset[place - 1] = data;
    }
    size++;
    /*for(int i = 0; i < size; i++){
        if (i == size - 1)
            printf("%c\n", dataset[i]);
        else
            printf("%c ", dataset[i]);
    }
    */
}

void delete(char opr2[6]){
    if (strcmp(opr2, "left") == 0){
        for(int i = 0; i < size - 1; i++)
            dataset[i] = dataset[i + 1];
    }
    else if (strcmp(opr2, "right") == 0)
        dataset[size - 1] = '\0';
    else{
        int place = atoi(opr2);
        for(int i = place - 1; i < size - 1; i++){
            dataset[i] = dataset[i + 1];
        }
    }
    size--;
    /*for(int i = 0; i < size; i++){
        if (i == size - 1)
            printf("%c\n", dataset[i]);
        else
            printf("%c ", dataset[i]);
    }*/
}

int main(void){
    char opr[7];
    while(scanf("%s", opr) != EOF){
        if (strcmp(opr, "insert") == 0){
            char opr2[6];
            char data;
            scanf("%s %c", opr2, &data);
            insert(opr2, data);
        }
        else if (strcmp(opr, "delete") == 0){
            char opr2[6];
            scanf("%s", opr2);
            delete(opr2);
        }
    }
    int count = 1, max = 0;
    for (int i = 0; i < size - 1; i++){
        if (dataset[i] == dataset[i + 1]){
            count++;
        }
        else{
            if(count > max)
                max = count;
                count = 1;
        }
    }
    max = count > max ? count : max;

    int found = 0;
    for(int i = 0; i <= size - max; i++){
        count = 1;
        for(int m = 1; m < max; m++){
            if (dataset[i] == dataset[i + m])
                count++;
        }   
        if (count == max) 
            printf("%c ", dataset[i]);
    }
    if (size > 0)
        printf("%d", max);
    else 
        printf("0");

    //for(int i = 0; i < size; i++)
      //  printf("%c ", dataset[i]);
    //printf("%d", size);
    
    return 0;
}
