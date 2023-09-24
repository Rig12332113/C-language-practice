#include <stdio.h>
#include <stdlib.h>
int main(void){
    int num = 0;
    scanf("%d", &num);
    int *numbers = (int *)malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++)
        scanf("%d", &numbers[i]);
    int found = 0, answer = 0;
    for (int i = 0; i < num && !found; i++){
        for (int j = i + 1; j < num && !found; j++){
            if (numbers[j] == numbers[i]){
                answer = numbers[i];
                found = 1;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}