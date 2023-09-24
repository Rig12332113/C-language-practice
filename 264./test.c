#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main(void){
    char name[200];
    scanf("%s", name);
    FILE *filein = fopen(name, "rb");
    assert(filein != NULL);
    int times[65537] = {0};
    short int temp = 0; 
    int num = 0;
    fscanf(filein, "%d", &num);
    for(int i = 0; i < num; i++){
        fscanf(filein, "%hd", &temp);
        //printf("%d\n", temp);
        times[temp + 32768]++;
    }
    fclose(filein);
    int max = 0, place = 0;
    for(int i = 0; i < 65536; i++)
        if (times[i] >= max){
            max = times[i];
            place = i;
        }
    
    printf("%d\n%d\n", place - 32768, max);
    return 0;
}