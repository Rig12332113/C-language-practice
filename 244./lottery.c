#include<stdio.h>
#include<stdbool.h>
int main(){
    int special[3], first[3], own[20] = {0};
    scanf("%d%d%d", &special[0], &special[1], &special[2]);
    scanf("%d%d%d", &first[0], &first[1], &first[2]);
    int num = 0; 
    bool valid = 0;
    while(scanf("%d", &own[num]) != EOF)
        num++;
    if (num  > 0)
        valid = 1;
    
    //檢查特別獎
    int prize = 0;
    for(int i = 0; i < 3 && valid; i++){
        for(int j = 0; j < num; j++){
            if (special[i] == own[j])
                prize += 2000000;
        }
    }

    //檢查頭獎與其他獎項
    for(int i = 0; i < 3 && valid; i++){
        for(int j = 0; j < num; j++){
            if (first[i] % 1000 == own[j] % 1000){
                if (first[i] % 10000 == own[j] %  10000){
                    if (first[i] % 100000 == own[j] %  100000){
                        if (first[i] % 1000000 == own[j] %  1000000){
                            if (first[i] % 10000000 == own[j] % 10000000){
                                if (first[i] == own[j])
                                    prize += 200000;
                                else
                                    prize += 40000;
                            }
                            else
                                prize += 10000;   
                            }
                        else
                            prize += 4000;
                    }
                    else
                        prize += 1000;
                }
                else
                    prize += 200;
            }
        }
    }
    printf("%d\n", prize);
    return 0;
}