#include<stdio.h>
#include<math.h>
int main(){
    double angle[3], length[4];
    int a[8];
    scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
    for(int i = 0; i <= 6; i+=2){
        length[i/2] = sqrt(a[i] * a[i] + a[i+1] * a[i+1]);
    }
    for(int i = 0; i <= 4; i+=2){
        angle[i/2] = acos((a[i] * a[i+2] + a[i+1] * a[i+3]) / length[i/2] / length[i/2 + 1]);
    }
    if((angle[0] + angle[1] + angle[2])> 3.14156)
        printf("1\n");
    else
        printf("0\n");
    
}
