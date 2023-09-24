#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    int num_of_1a = 0, num_of_1b = 0;
    long long int tempa = *(long long int *)a, tempb = *(long long int *)b;
    while(tempa > 0){
        if (tempa % 2 == 1)
            num_of_1a++;
        tempa /= 2;
    }
    while(tempb > 0){
        if (tempb % 2 == 1)
            num_of_1b++;
        tempb /= 2;
    }
    if (num_of_1a > num_of_1b)
        return 1;
    else if(num_of_1a < num_of_1b)
        return -1;
    else{
        if (*(long long int *)a > *(long long int *)b)
            return 1;
        else
            return -1;
    }
}
int main(void){
    long long int data[1000] = {0};
    int num = 0;
    while(scanf("%lld", &data[num]) != EOF){
        num++;
    }
    qsort(data, num, sizeof(long long int), compare);
    for(int i = 0; i < num; i++)
        printf("%lld\n", data[i]);
    return 0;
}