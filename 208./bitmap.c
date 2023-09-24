#include<stdio.h>
int main(void){
    int column = 0, row = 0;
    char sign_a = {'0'}, sign_b = {'0'};
    scanf("%d%d", &column, &row);
    scanf("\n%c %c", &sign_a, &sign_b);
    unsigned int num = 0, i = 0;
    int bitmap[35000];
    while (i < column * row){
        scanf("%d", &num);
        for (int j = 31; j >= 0; j--){
            bitmap[i+j] = num % 2;
            num /= 2; 
        }
        i += 32;
    }
    for (int i = 0; i < column * row; i++){
        //printf("%d", bitmap[i]);
        if (bitmap[i] == 1)
            printf("%c", sign_a);
        else 
            printf("%c", sign_b);
        if (i % column == column - 1)
            printf("\n");    
    }
    return 0;
}