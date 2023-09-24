#include<stdio.h>
int count(int goal, int *numbers, int num){
    if(goal == 0 && num >= 0) 
        return 1;
    else if (goal != 0 && num == 0)
        return 0;
    else{
        if (goal < *numbers)
            return count(goal, (numbers + 1), num - 1);
        else
            return count(goal, (numbers + 1), num - 1) + count(goal - *numbers, (numbers + 1), num - 1);
    }
}

int main(void){
    int num = 0;
    scanf("%d", &num);
    int numbers[20];
    for (int i = 0; i < num; i++)
        scanf("%d", &numbers[i]);
    int goal;
    while(scanf("%d", &goal) != EOF){
        printf("%d\n", count(goal, numbers, num));
    }
    
    return 0;
}