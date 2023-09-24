#include <stdio.h>
int main(void){
    int m = 0, i = 0;
    scanf("%d", &m);
    int data[50] = {0};
    while(i < m){
        scanf("%d", &data[i]);
        i++;
    }
    int temp = 0;
    for(int i = m - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (data[j] > data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    i = 0;
    while(i < m){
        printf("%d", data[i]);
        i++;
    }
    return 0;
}