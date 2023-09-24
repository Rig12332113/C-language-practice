#include<stdio.h>
int main(){
    int num = 0, totalfeet = 0, totaltail = 0;
    scanf("%d %d %d", &num, &totalfeet, & totaltail);
    int chicken = 0, rabbit = 0, crab = 0;
    crab = num - totaltail;
    rabbit = (totalfeet - 8 * crab - 2 * totaltail) / 2;
    chicken = num - crab - rabbit;
    printf("%d\n%d\n%d\n", chicken, rabbit, crab); 
    return 0;

}