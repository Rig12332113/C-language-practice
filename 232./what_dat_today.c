#include<stdio.h>
#include<stdbool.h>
int main(){
    int year = 0, date = 0;
    scanf("%d %d", &year, &date);
    int num = 0;
    scanf("%d", &num);
    while(num > 0){
        int month = 0, day = 0, sum = 0;
        bool valid = 0;
        scanf("%d %d", &month, &day);

        //判定輸入是否合理
        switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(day > 31 || day < 1)
                    printf("-2\n");
                else
                    valid = 1;
                break;
            case 4: case 6: case 9: case 11: 
                if (day > 30 || day < 1)
                    printf("-2\n");
                else
                    valid = 1;
                break;
            case 2:
                if(!(year % 4)){
                    if(!(year % 100)){
                        if(!(year % 400) || !(year % 1000)){
                            if(day > 29 || day < 1)
                                printf("-2\n");
                            else
                                valid = 1;
                        }
                        else if(day > 28 || day < 1)
                            printf("-2\n");
                        else 
                            valid = 1;
                    }
                    else if(day > 29 || day < 1)
                        printf("-2\n");
                    else 
                        valid = 1;
                }
                else if(day > 28 || day < 1)
                    printf("-2\n");
                else
                    valid = 1;
                break;
            default:
                printf("-1\n");
                break;
        }

        //計算星期幾
        if(valid){
            for(int i = month - 1; i > 0; i--){
                switch(i){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        sum = sum + 31;
                        break;
                    case 4: case 6: case 9: case 11: 
                        sum = sum + 30;
                        break;
                    case 2:
                        if(!(year % 4)){
                            if(!(year % 100)){
                                if(!(year % 400) || !(year % 1000))
                                    sum = sum + 29;
                                else
                                    sum = sum + 28;
                            }
                            else
                                sum = sum + 29;
                        }
                        else
                            sum = sum + 28;
                    break;
                }
            }
            printf("%d\n", (date + sum + day - 1) % 7);
        }
        num--;  
    } 
    return 0; 
}