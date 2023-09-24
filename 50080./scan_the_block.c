#include <stdio.h>
int main(void){
    int num = 0;
    while(scanf("%d", &num) != EOF){
        //printf("num:%d\n", num);
        int max = 0, min = 0, data = 0, times = 0;
        while(times < num && scanf("%d", &data) != EOF){
            //printf("data:%d\n", data);
            if (times == 0){
                max = data;
                min = data;
            }
            else{
                if (data > max)
                    max = data;
                if (data < min)
                    min = data;
            } 
            times++; 
        }
        if (times == num)
            printf("%d\n", max);
        else
            printf("%d\n", min);
    }
    return 0;
}