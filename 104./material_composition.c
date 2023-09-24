#include <stdio.h>
int checker(int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC, int a, int b, int c){
    if(a < 0 || b < 0 || c < 0)
        return 0;
    else if (a == 0 && b == 0 && c == 0)
        return 1;
    else{
        return checker(DA, DB, DC, EA, EB, EC, FA ,FB, FC, a - DA, b - DB, c - DC) ||
               checker(DA, DB, DC, EA, EB, EC, FA ,FB, FC, a - EA, b - EB, c - EC) ||
               checker(DA, DB, DC, EA, EB, EC, FA ,FB, FC, a - FA, b - FB, c - FC);
    }
}
void check(int times, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC){
    if(times > 0){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int outcome = checker(DA, DB, DC, EA, EB, EC, FA ,FB, FC, a, b, c);
        if (outcome)    
            printf("yes\n");
        else
            printf("no\n");
        times--;
        check(times, DA, DB, DC, EA, EB, EC, FA ,FB, FC);
    }
}
int main(void){
    int DA, DB, DC, EA, EB, EC, FA ,FB, FC;
    scanf("%d%d%d%d%d%d%d%d%d", &DA, &DB, &DC, &EA, &EB, &EC, &FA, &FB, &FC);
    int times = 0;
    scanf("%d", &times);
    check(times, DA, DB, DC, EA, EB, EC, FA ,FB, FC);
    return 0;
}