#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}
int main(void){
    char data[64][50];
    int index = 0;
    while(gets(data[index]) != NULL){
        index++;
    }
    qsort(data, index, 50 * sizeof(char), compare);
    for(int i = 0; i < index; i++){
        printf("%s\n", data[i]);
    }
    return 0;
}