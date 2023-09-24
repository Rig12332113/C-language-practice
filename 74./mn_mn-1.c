#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    int number[100000];
    for(int i = 0; i < num; i++){
        scanf("%d", &number[i]);
    }
    int devider = 0;
    scanf("%d", &devider);
    int count[200000];
    
    for(int j = 0; j < num; j++){
        int temp = number[j] % devider;
        count[temp]++;
        temp = 0;
    }   
    
    for(int i = 0; i < devider; i++){
        printf("%d\n", count[i]);
    }
    return 0;
}