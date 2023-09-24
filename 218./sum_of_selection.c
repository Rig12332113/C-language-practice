#include<stdio.h>
int method(int option, int choose);
int main(){
    int option = 0, choose = 0;
    scanf("%d%d", &option, &choose);
    int sum = 0;
    for(int i = 0; i < choose + 1; i++)
        sum += method(option, i);
    printf("%d\n", sum);
    return 0;
}
int method(int option, int choose){
    int ans = 1;
    for(int i = 0; i < choose; i++){
        ans *= (option - i);
        ans /= (i + 1);
    }
    return ans;
}