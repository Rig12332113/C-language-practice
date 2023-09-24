#include <stdio.h>
#include <stdlib.h>
#include "time_object.c"
int main(void){
    int clock_num = 0;
    scanf("%d", &clock_num);
    Time *clock = (Time *)malloc(sizeof(Time) * clock_num);
    char buff[10];
    gets(buff);
    char cmd;
    while(scanf("%c", &cmd) != EOF){
        if (cmd == 'i'){
            int temp;
            scanf("%d", &temp);
            initTime(clock + temp);
        }
        else if (cmd == 's'){
            int temp, hour, minute, second;
            scanf("%d%d%d%d", &temp, &hour, &minute, &second);
            setTime(clock + temp, hour, minute, second);
        }
        else if (cmd == 'a'){
            int temp, hour, minute, second;
            scanf("%d%d%d%d", &temp, &hour, &minute, &second);
            addTime(clock + temp, hour, minute, second);
        }
        else if (cmd == 'p'){
            int temp;
            scanf("%d", &temp);
            printTime(clock + temp);
        }
    }
    return 0;
}