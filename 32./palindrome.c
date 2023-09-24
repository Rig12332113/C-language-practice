#include <stdio.h>
#include <stdlib.h>
int main(void){
    int data[100];
    int next = 0, index = 0;
    while(scanf("%d", &next) != EOF){
        data[index] = next;
        index++;
    }
    int *len = (int *)malloc(sizeof(int) * index);
    for(int i = 0; i < index; i++){
        for(int j = 0; j <= index / 2; j++){
            if (i - j < 0 || i + j > index - 1)
                break;
            else if (data[i + j] == data[i - j])
                len[i] = 2 * j + 1;
            else 
                break;
        }
    }
    for(int i = 0; i < index; i++){
        for(int j = 0; j <= index / 2; j++){
            if (i - j < 0 || i + j > index - 2)
                break;
            else if (data[i - j] == data[i + 1 + j])
                len[i] = 2 * (j + 1);
            else 
                break;
        }
    }
    int place = 0, max = 0;
    for(int i = 0; i < index; i++){
        for (int j = 1; i + j < index; j++){
            int len1, len2;
            if (len[i] % 2 == 1)
                len1 = (len[i] - 1) / 2;
            else
                len1 = len[i] / 2;
            if (len[i + j] % 2 == 1)
                len2 = (len[i + j] - 1) / 2;
            else
                len2 = len[i] / 2;
            if (len[i] + len[i + j] - len1 - len2 > max){
                place = i;
                max = len[i] + len[i + j] - len1 - len2;
            }
        }
    }
    printf("%d %d\n", place, max);
    for(int i = 0; i < index; i++)
        printf("%d ", len[i]);
    return 0;
}