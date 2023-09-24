#include "node.h"
#include "node.c"
int main(void){
    struct node A, B, C, D;
    A.next = &B;
    B.next = &C;
    C.next = NULL;
    printf("%p %p %p\n", &A, &B, &C);
    //printf("%p %p %p\n", (A.next), (B.next), (C.next));
    printf("%p", getNode(&A, 5));
    return 0;
}