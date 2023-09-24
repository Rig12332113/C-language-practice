#include<stdio.h>
int main(void){
    int row = 0, column = 0;
    scanf("%d%d", &row, &column);
    int data;
    int i = 0, highest_i = 0, highest_j, highest = 0;
    while(i < row){
        int j = 0, first = 0, second = 0, first_j = 0, second_j = 0;
        while(j < column){
            int data = 0;
            scanf("%d", &data);
            if (data >= first){
                second = first;
                first = data;
                second_j = first_j;
                first_j = j + 1;
            }
            else if (data >= second && data < first){
                second = data;
                second_j = j + 1;
            }
            j++;
        }
        if (first >= highest){
            highest = first;
            highest_i = i + 1;
            highest_j = first_j;
        }
        printf("%d %d\n", first_j, second_j); 
        i++;
    }
    printf("%d %d", highest_i, highest_j);
    return 0;
}