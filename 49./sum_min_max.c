#include<stdio.h>
int main(){
    int num = 0, devider = 0;
    scanf("%d%d", &num, &devider);
    int remainder[1000][3];
    for(int i = 0; i<1000; i++){
        remainder[i][0] = 0;
        remainder[i][1] = 0;
        remainder[i][2] = 10000;
    }

    while(num > 0){
        int temp = 0;
        scanf("%d", &temp);
        int k = temp % devider; 
        remainder[k][0] += temp;
        if(remainder[k][1] < temp)
            remainder[k][1] = temp;
        if(remainder[k][2] > temp)
            remainder[k][2] = temp;
        num--;
    }
    for(int i = 0; i < devider; i++){
        if(remainder[i][2] == 10000)
            remainder[i][2] = 0;
        printf("%d %d %d\n",remainder[i][0], remainder[i][1], remainder[i][2]);
    }
    return 0;
}