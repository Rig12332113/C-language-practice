#include<stdbool.h>
#include "eval.h"
 
int eval(int exp[]) {
    int num = (exp[0] - 1) / 2;
    int temp = 0, place;
    bool mul_and_dev = 1, plus_and_min = 0;
    for(int i = 2; i < exp[0]; i += 2)
        if (!(exp[i] > 0 && exp[i] < 5))
            return -2147483646;
    while(num > 0){
        mul_and_dev = 1;
        for(int i = 2; i < exp[0] && mul_and_dev; i += 2){
            if (exp[i] == 3){
                temp = exp[i-1] * exp[i+1];
                place = i;
                mul_and_dev = 0;
            }
            else if (exp[i] == 4){
                if (exp[i+1] == 0)
                    return -2147483647;
                else{
                    temp = exp[i-1] / exp[i+1];
                    place = i;
                    mul_and_dev = 0;
                }
            }
        }
        plus_and_min = mul_and_dev;
        for(int i = 2; i < exp[0] && plus_and_min; i += 2){
            if (exp[i] == 1){
                temp = exp[i-1] + exp[i+1];
                place = i;
                plus_and_min = 0;
            }
            else if (exp[i] == 2){
                temp = exp[i-1] - exp[i+1];
                place = i;
                plus_and_min = 0;
            }
        }
        for(int i = 1; i <= exp[0] - 2; i++){
            if(i == place - 1)
                exp[i] = temp;
            else if (i > place - 1)
                exp[i] = exp[i+2];       
        }
    exp[0] -= 2;
    num--;
    }
    return exp[1];
}