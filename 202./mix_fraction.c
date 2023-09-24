#include<stdio.h>
#include<stdlib.h>
#define ADD 0
#define MINUS 1
#define MULTIPLE 2
#define DEVIDE 3
int add(int a, int b, int c, int e, int f, int g){
    int top_1 = a * c + b;
    int top_2 = e * g + f;
    int ans_top = top_1 * g + top_2 * c;
    int ans_bottom = c * g;
    if(ans_top % ans_bottom == 0){
        printf("%d\n%d\n%d\n",ans_top / ans_bottom, 0, 1);
        return 0;
    }
    int i = 2;
    while(i < 10000){
        if(ans_top % i == 0 && ans_bottom % i == 0){
            ans_top /= i;
            ans_bottom /= i;
        }
        else
            i++;
    }
    printf("%d\n%d\n%d\n", ans_top / ans_bottom, abs(ans_top % ans_bottom), abs(ans_bottom));
    return 0;
}
int minus(int a, int b, int c, int e, int f, int g){
    int top_1 = a * c + b;
    int top_2 = e * g + f;
    int ans_top = top_1 * g - top_2 * c;
    int ans_bottom = c * g;
    if(ans_top % ans_bottom == 0){
        printf("%d\n%d\n%d\n",ans_top / ans_bottom, 0, 1);
        return 0;
    }
    int i = 2;
    while(i < 10000){
        if(ans_top % i == 0 && ans_bottom % i == 0){
            ans_top /= i;
            ans_bottom /= i;
        }
        else
            i++;
    }
    printf("%d\n%d\n%d\n", ans_top / ans_bottom, abs(ans_top % ans_bottom), abs(ans_bottom));
    return 0;
}
int multiple(int a,int b, int c, int e, int f, int g){
    int top_1 = a * c + b;
    int top_2 = e * g + f;
    int ans_top = top_1 * top_2;
    int ans_bottom = c * g;
    if(ans_top % ans_bottom == 0){
        printf("%d\n%d\n%d\n",ans_top / ans_bottom, 0, 1);
        return 0;
    }
    int i = 2;
    while(i < 10000){
        if(ans_top % i == 0 && ans_bottom % i == 0){
            ans_top /= i;
            ans_bottom /= i;
        }
        else
            i++;
    }
    printf("%d\n%d\n%d\n", ans_top / ans_bottom, abs(ans_top % ans_bottom), abs(ans_bottom));
    return 0;
}
int devide(int a, int b, int c ,int e, int f, int g){
    int top_1 = a * c + b;
    int top_2 = e * g + f;
    int ans_top = top_1 * g;
    int ans_bottom = c * top_2;
    if(ans_top % ans_bottom == 0){
        printf("%d\n%d\n%d\n",ans_top / ans_bottom, 0, 1);
        return 0;
    }
    int i = 2;
    while(i < 10000){
        if(ans_top % i == 0 && ans_bottom % i == 0){
            ans_top /= i;
            ans_bottom /= i;
        }
        else
            i++;
    }
    printf("%d\n%d\n%d\n", ans_top / ans_bottom, abs(ans_top % ans_bottom), abs(ans_bottom));
    return 0;
}
int main(void){
    int a = 0, b = 0, c = 0, operator = 0, e = 0, f = 0, g = 0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &operator);
    scanf("%d %d %d", &e, &f, &g);
    if (a < 0)
        b *= -1;
    if (e < 0)
        f *= -1; 
    switch(operator){
        case ADD:
            add(a, b, c, e, f, g);
            break;
        case MINUS:
            minus(a, b, c, e, f, g);
            break;
        case MULTIPLE:
            multiple(a, b, c, e, f, g);
            break;
        case DEVIDE:
            devide(a, b, c, e, f, g);
            break;
    }
    return 0;
}
