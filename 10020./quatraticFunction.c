#include <stdio.h>
#include <math.h>
int main(void){
    double a = 0, b = 0, c = 0;
    while(scanf("%lf%lf%lf", &a, &b, &c) == 3){
        double ans1 = 0, ans2 = 0;
        ans1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        ans2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (ans1 > ans2)
            printf("%.20lf %.20lf\n", ans2, ans1);
        else
            printf("%.20lf %.20lf\n", ans1, ans2);
    }
    return 0;
}