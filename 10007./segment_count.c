#include <stdio.h>
int main(void){
    int num = 0;
    while(scanf("%d", &num) != EOF){
        int current = 0, next = 0, count = 0;
        scanf("%d", &current);
        for(int i = 0; i < num - 1; i++){
            scanf("%d", &next);
            if (current != next){
                count++;
                current = next;
            }
            else 
                continue;
        }
        printf("%d\n", count + 1);
    }
    return 0;
}