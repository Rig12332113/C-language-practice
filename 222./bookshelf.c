#include<stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
void move(int *shelf, int bookplace, int next){
    for(int i = bookplace; i < 7; i++)
        shelf[i] = shelf[i+1];
    shelf[7] = next;
}

int main(void){
    int shelf[8] = {0};
    int x = 0;
    while(ReadInt(&x)){
        int onshelf = 0;
        for(int i = 7; i >= 0; i--){
            if (x == shelf[i]){
                move(shelf, i, x);
                onshelf = 1;
                break;
            }
        }
        if (!onshelf)
            move(shelf, 0, x);
    }
    for(int i = 0; i < 7; i++)
        printf("%d ", shelf[i]);
    printf("%d", shelf[7]);
    return 0;
}