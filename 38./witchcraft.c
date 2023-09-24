#include<stdio.h>
#include<stdbool.h>
long int A = 0, B = 0, C = 0;
bool compute(int requirement, int a, int b, int c){
    bool valid = 0;
    if (requirement == 0)
        return 1;
    else if ((requirement < A && requirement < B && requirement < C))
        return 0;

    if (a > 0){
        for(long int i = 0; i <= a && requirement >= A * i; i++){
            //printf("1");
            valid = compute(requirement - A * i, 0, b, c);
            if (valid)
                return 1;
        }
        return 0;
    }
    else if(b > 0){
        for(long int i = 0; i <= b && requirement >= B * i; i++){
            //printf("2");
            valid = compute(requirement - B * i, 0, 0, c);
            if (valid)
                return 1;
        }
        return 0;
    }
    else if (c > 0){
        for(long int i = 0; i <= c && requirement >= C * i; i++){
            //printf("3");
            valid = compute(requirement - C * i, 0, 0, 0);
            if (valid)
                return 1;
        }
        return 0;
    }
    else 
        return 0;

}
int main(void){
    int times = 0, i = 0;
    scanf("%d", &times);
    while(i < times){
        long int requirement = 0, a = 0, b = 0, c = 0;
        scanf("%ld%ld%ld%ld%ld%ld%ld", &requirement, &a, &b, &c, &A, &B, &C);
        bool valid = compute(requirement, a, b, c);
        if(valid)
            printf("yes\n");
        else
            printf("no\n");
        i++;
    }
    return 0;
}