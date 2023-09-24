#include <stdio.h>
int main(void){
    int A = 0, B = 0, type = 0;
    scanf("%d%d%d", &A, &B, &type);
    while(type == 0){
        int temp = 0;
        while(scanf("%d", &temp) != EOF){
            if (A >= temp){
                A -= temp;
                printf("%d %d\n", A, B);
            }
            else if (B >= temp){
                B -= temp;
                printf("%d %d\n", A, B);
            }
            else
                printf("%d %d\n", A, B);
        }
        break;
    }
    while(type == 1){
        int temp = 0;
        while(scanf("%d", &temp) != EOF){
            if (A - temp < 0 && B - temp >= 0){
                B -= temp;
                printf("%d %d\n", A, B);
            }
            else if (A - temp >= 0 && B - temp < 0){
                A -= temp;
                printf("%d %d\n", A, B);
            }
            else if (A - temp <= B - temp && A - temp >= 0 && B - temp >= 0){
                A -= temp;
                printf("%d %d\n", A, B);
            }
            else if (A - temp > B - temp && A - temp >= 0 && B - temp >= 0){
                B -= temp;
                printf("%d %d\n", A, B);
            }
            else
                printf("%d %d\n", A, B);
        }
        break;
    }
    return 0;
}