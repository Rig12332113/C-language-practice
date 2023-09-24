#include<stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    int number[1000];
    for(int i = 0; i < num; i++){
        scanf("%d", &number[i]);
    }
    int odd[1000], even[1000];
    int o = 0, e = 0;
    for(int i = 0; i < num; i++){
        if(number[i] % 2){
            odd[o] = number[i];
            o++;
        }
        else{
            even[e] = number[i];
            e++;
        }
    }
    for(int i = 0; i < o - 1; i++){
        printf("%d ", odd[i]);
    }
    printf("%d\n",odd[o-1]);
    for(int i = 0; i < e - 1; i++){
        printf("%d ", even[i]);
    }
    printf("%d", even[e-1]);
    return 0;
}