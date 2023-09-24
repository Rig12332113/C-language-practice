#include <stdio.h>
int main(void){
    int arrive = 0, A = 0, B = 0;
    int A_ready = 0, B_ready = 0;
    while (scanf("%d%d%d", &arrive, &A, &B) != EOF){
        A_ready = (A_ready > arrive ? A_ready : arrive) + A;
        B_ready = (A_ready > B_ready ? A_ready : B_ready) + B;
        printf("%d\n", B_ready);
    }
    return 0;
}