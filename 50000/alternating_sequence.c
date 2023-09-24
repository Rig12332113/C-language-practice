#include<stdio.h>
#include<stdbool.h>

int main(void){
    int rule = 0;
    scanf("%d", &rule);
    int next = 0, count = 0, max = 0, temp = 0;
    bool sign = 1;
    while(scanf("%d", &next) != 0){
        if (sign){
            if (next > 0 && count < rule - 1){
                //printf(" 0");
                count++;
            }
            else if (next > 0 && count == rule - 1){
                //printf(" 1");
                count = 0;
                sign = 0;
                temp += rule;
                if (temp > max && temp >= rule * 3)
                    max = temp;
            }
            else if (next == 0){
                //printf(" 2");
                break;
            }
            else{
                //printf(" 3");
                count = 0;
                sign = 1;
                temp = 0;
            }
        }
        else if (!(sign)){
            if (next < 0 && count < rule - 1){
                //printf(" -0");
                count++;
            }
            else if (next < 0 && count == rule - 1){
                //printf(" -1");
                count = 0;
                sign = 1;
                temp += rule;
            }
            else if (next == 0){
                //printf(" -2");
                if (temp > max && temp >= rule * 3)
                    max = temp;
                break;
            }
            else{
                if (count == 0){
                    //printf(" -3");
                    count = 0;
                    sign = 0;
                    temp = rule;
                }
                else{
                    //printf(" -4");
                    count = 1;
                    sign = 1;
                    temp = 0;
                }
            } 
        }           
    }
    printf("%d", max);
    return 0;
}