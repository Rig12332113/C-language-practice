#include<stdio.h>
int main(){
    //儲存輸入
    int length1 = 0;
    scanf("%d", &length1);
    int poly1[100];
    for(int i = 0; i < length1; i++)
        scanf("%d", &poly1[i]);
    int length2 = 0;
    scanf("%d", &length2);
    int poly2[100];
    for(int i = 0; i < length2; i++)
        scanf("%d", &poly2[i]);
    
    //計算
    int ans[200];
    for(int i = 0;i < 200; i++)
        ans[i] = 0;
    for(int i = 0;i < length1; i++){
        for(int j = 0; j < length2; j++){
            ans[i+j] += poly1[i] * poly2[j]; 
        }
    }
    //輸出
    for(int i = 0; i < length1 + length2 - 2; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[length1 + length2 - 2]);
    return 0;
}