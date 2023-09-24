#include<stdio.h>
#define PI 3.1415926
int main(){
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a > b){
        if (c <= b)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI);
        else if (c > b && c <= a)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI + (c - b) * (c - b) * PI / 4.0); 
        else if (c > a)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI + (c - b) * (c - b) * PI / 4.0 + (c - a) * (c - a) * PI / 4.0);
    }
    else if (b > a){
        if (c <= a)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI);
        else if (c > a && c <= b)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI + (c - a) * (c - a) * PI / 4.0); 
        else if (c > b)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI + (c - b) * (c - b) * PI / 4.0 + (c - a) * (c - a) * PI / 4.0);
    }
    else if (b == a){
        if (c <= b)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI);
        if (c > b)
            printf("%lf\n", 3.0 / 4.0 * c * c * PI + (c - b) * (c - b) * PI / 2.0);
    }
    return 0;
}