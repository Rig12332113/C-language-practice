#include<stdio.h>
int surfaceArea(int l, int w, int d, int e){
    int outerSA = l * w;
    int innerSA = 2 * d * ((l - 2 * e) + (w - 2 * e));
    return outerSA + innerSA;
}
int volume(int a, int b, int c, int d, int e){
    int volume = a * b * c;
    int hole = 2 * d * ((a - 2 * e) * (b - 2 * e) + (b - 2 * e) * (c - 2 * e) + (a - 2 * e) * (c - 2 * e));
    return volume - hole; 

}
int main(){
    int a = 0, b =0, c = 0, d = 0, e = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%d\n", 2 * (surfaceArea(a,b,d,e) + surfaceArea(a,c,d,e) + surfaceArea(c,b,d,e)));
    printf("%d\n", volume(a, b, c, d, e));
    return 0;
}
