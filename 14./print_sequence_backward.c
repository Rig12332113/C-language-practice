#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    int number[1000];
    for(int i = 0; i < num; i++){
        scanf("%d", &number[i]);
    }
    for(int i = num - 1; i > 0; i-- ){
        printf("%d ", number[i]);
    }
    printf("%d", number[0]);
    return 0;
}