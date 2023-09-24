#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < i + 1; j++){
            printf("%d", j + 1);
        }

    }
    return 0;
}