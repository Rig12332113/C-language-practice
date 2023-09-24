#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    int year, month, date;
}Date;
int compare(const void *a, const void *b){
    if (((Date *)a)->year > ((Date *)b)-> year)
        return 1;
    else if (((Date *)a)->year < ((Date *)b)-> year)
        return -1;
    else if (((Date *)a)->month > ((Date *)b)-> month)
        return 1;
    else if (((Date *)a)->month < ((Date *)b)-> month)
        return -1;
    else if (((Date *)a)->date > ((Date *)b)-> date)
        return 1;
    else if (((Date *)a)->date < ((Date *)b)-> date)
        return -1;
    else 
        return 0;
}
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
int main(void){
    int num = 0;
    scanf("%d", &num);
    Date *data = (Date *)malloc(num * sizeof(Date));
    for(int i = 0; i < num; i++){
        ReadInt(&(data + i)->year);
        ReadInt(&(data + i)->month);
        ReadInt(&(data + i)->date);
    }
    qsort(data, num, sizeof(Date), compare);
    for(int i = 0; i < num; i++)
        printf("%d %d %d\n", (data + i)->year, (data + i)->month, (data + i)->date);
    return 0;
}