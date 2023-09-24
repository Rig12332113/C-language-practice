#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void){
    int time = 0;
    scanf("%d", &time);
    while(time > 0){
        int dif = 0;
        char a[80], b[80];
        bool similar = 1;
        scanf("%s%s", a, b);
        //同樣長度
        if (strlen(a) == strlen(b)){
            for(int i = 0; i < strlen(a); i++){
                if (a[i] != b[i] && dif == 0){
                    if (a[i] == b[i+1] && b[i] == a[i+1]){
                        i = i + 2;
                        dif++;
                        continue;
                    }
                    else{
                        similar = 0;
                        break;
                    }
                }
                else if (a[i] != b[i] && dif > 0)
                    similar = 0;
                else
                    continue;
            }
        }

        //不同長度
        else if (strlen(a) + 1 == strlen(b) || strlen(a) == strlen(b) + 1){
            int length = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
            char *shortone = strlen(a) < strlen(b) ? a : b;
            char *longone = strlen(a) < strlen(b) ? b : a;
            for(int i = 0; i < length; i++){
                if (dif == 0){
                    if (*(shortone + i) != *(longone + i))
                        dif++;
                    else
                        continue;
                }
                else if (dif == 1){
                    if (*(shortone + i - 1) == *(longone + i))
                        continue;
                    else{
                        similar = 0;
                        break;
                    }
                }
            }
        }
        else
            similar = 0;
        if (similar == 1)
            printf("yes\n");
        else
            printf("no\n");
        time--;
    }
    return 0;
}
