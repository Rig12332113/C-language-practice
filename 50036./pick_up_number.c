#include<stdio.h>
int count(int numbers[20],int remain, int num, int index, int limit){
    if (index > num - remain)
        return 0;
    if (remain == 0 && limit >= 0)
        return 1;
    else if (remain == 0 && limit < 0)
        return 0;
    else 
        return count(numbers, remain - 1, num, index + 1, limit - numbers[index])
             + count(numbers, remain, num, index + 1, limit);
}
int main(void){
    int least = 0, num = 0, limit = 0;
    scanf("%d%d%d", &least, &num, &limit);
    int numbers[20];
    for(int i = 0; i < num; i++)
        scanf("%d", &numbers[i]);
    int ans = 0;
    for(int i = least; i <= num; i++)
        ans += count(numbers, i, num, 0, limit);
    printf("%d", ans);   
    return 0;
}