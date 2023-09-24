#include<stdio.h>
int main(void){
    int number;
    while(scanf("%d", &number) != EOF){
        int binary_num[32] = {0};
        int i = 0;
        while (number >= 1){
            binary_num[i] = number % 2;
            number /= 2;
            i++;
        }
        int consecutive = 1, maximum = 1;
        for(int j = 0; j < 32; j++){
            if (binary_num[j] == 1 && binary_num[j+1] == 1){
                consecutive++;
            }
            else{
                if (consecutive > maximum)
                    maximum = consecutive;
                consecutive = 1;
            }
        }
        printf("%d\n", maximum);
    }
    return 0;
}