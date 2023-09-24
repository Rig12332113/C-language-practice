#include<stdio.h>
int main(void){
    int train_num = 0, size = 0; 
    int weight[16][16] ={0};
    scanf("%d%d", &train_num, &size);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            weight[i][j] = 1;
    
    int threshold = 2 * size * size;
    for(int i = 0; i < train_num; i++){
        int train[16][16] = {0};
        int sum = 0, valid;
        scanf("%d", &valid);
        for(int m = 0; m < size; m++)
            for(int n = 0; n < size; n++){
                scanf("%d", &train[m][n]);
                sum += weight[m][n] * train[m][n];
            }
        if (valid == (sum >= threshold))
            continue;   
        else{
            for(int m = 0; m < size; m++)
                for(int n = 0; n < size; n++){
                    if (train[m][n] == 1)
                        weight[m][n] *= 2;
                }
        }
        /*for(int m = 0; m < size; m++)
            for(int n = 0; n < size; n++){
                if (n == size - 1)
                    printf("%d\n", weight[m][n]);
                else
                    printf("%d ", weight[m][n]);
            }
        */
    }
    int test_num = 0;
    scanf("%d", &test_num);
    for(int i = 0; i < test_num; i++){
        int test[16][16] = {0};
        int sum = 0;
        for(int m = 0; m < size; m++)
            for(int n = 0; n < size; n++){
                scanf("%d", &test[m][n]);
                sum += weight[m][n] * test[m][n];
            }
        if (sum < threshold)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}