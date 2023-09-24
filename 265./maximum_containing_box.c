#include<stdio.h>
int main(void){
    int num = 0, temp = 0;
    int x[100] = {0}, y[100] = {0};
    while(scanf("%d", &temp) != EOF){
        if (num % 2 == 0){
            x[num/2] = temp;
            num++;
        }
        else{
            y[(num-1)/2] = temp;
            num++;
        }
    }
   
    int x_max = 0, x_min = 10000;
    for(int i = 0; i < num / 2; i++){
        if (x[i] > x_max)
            x_max = x[i];
        if (x[i] < x_min)
            x_min = x[i];
    }
    int y_max = 0, y_min = 10000;
    for(int i = 0; i < num / 2; i++){
        if (y[i] > y_max)
            y_max = y[i];
        if (y[i] < y_min)
            y_min = y[i];
    }
    printf("%d\n", (x_max - x_min) * (y_max - y_min));
    
}