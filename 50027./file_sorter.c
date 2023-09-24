#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;
int namecheck(char *name){
    int len = strlen(name);
    for (int i = 0; i < len; i++){
        if (isalpha(name[i]) == 0 && name[i] != ' ')
            return 0;
    }
    return 1;
}
int compare(const void *a, const void *b){
    Account *people1 = (Account *)a;
    Account *people2 = (Account *)b;
    if (strcmp(people1->name, people2->name) > 0)
        return 1;
    else if (strcmp(people1->name, people2->name) == 0)
        return 0;
    else 
        return -1;
}
int main(void){
    char input[80], output[80];
    scanf("%s%s", input, output);
    FILE *inputfile = fopen(input, "rb");
    assert(input != NULL);
    FILE *outputfile = fopen(output, "wb");
    Account data[1024];
    int data_num = fread(data, sizeof(Account), 1024, inputfile);
    qsort(data, data_num, sizeof(Account), compare);
    //for(int i = 0; i < data_num; i++)
        //printf("%d %s %d\n", data[i].balance, data[i].name, data[i].gender);
    for(int i = 0; i < data_num; i++){
        if (data[i].balance < 0){
            //printf("case1");
            continue;
        }
        else if (data[i].gender != 0 && data[i].gender != 1){
            //printf("case2");
            continue;
        }
        else if(namecheck(data[i].name) == 0){
            //printf("case3");
            continue;
        }
        //printf("case4");
        fwrite(&data[i], sizeof(Account), 1, outputfile);
    }
    return 0;
}