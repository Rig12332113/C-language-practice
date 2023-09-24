#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    for(int i = 1; i < num; i++){
        printf("%d\n", i);
    }
    for(int i = num; i > 0; i--){
        printf("%d\n", i );
    }
    return 0;
}