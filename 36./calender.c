#include<stdio.h>
#include<stdbool.h>
int main(){
    int year = 0, month = 0, date = 0;
    scanf("%d%d%d", &year, &month, &date);
    int day = 0;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day = 31;
            break;
        case 4: case 6: case 9: case 11:
            day = 30;
            break;
        case 2:
            if(!(year % 4) && (year % 100 || !(year % 400)))
                day = 29;
            else
                day = 28;   
    }

    bool valid = 1;
    if (month > 12 || month < 1 || date > 7 || date < 0){
        printf("invalid\n");
        valid = 0;
    }  

    while(valid){
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        int count = 0;
        for(int j = 0; j < date; j++){
            printf("   ");
            count++;
        }
        for(int i = 1; i < day + 1; i++){
            if ((count % 7) == 0 && (count != 0))
                printf("\n");
            printf("%3d", i);
            count++;
        }
        printf("\n=====================\n");
        valid = 0;
    }
    return 0;
}