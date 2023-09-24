#include<stdio.h>
int judge(int a, int b, int c);
int main(){
    int num = 0;
    scanf("%d", &num);
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0; 
    while(num > 0){
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        int length1 = 0, length2 = 0, length3 = 0;
        length1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        length2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        length3 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
        int type = judge(length1, length2, length3);
        switch(type){
            case 1: 
                printf("right\n");
                break;
            case 2:
                printf("obtuse\n");
                break;
            case 3:
                printf("acute\n");
                break;
            case 4:
                printf("isosceles\n");
        }
        num--;
    }
    return 0;
}
int judge(int a, int b, int c){
    if(a == b|| b == c || c == a)
        return 4;                           //isosceles triangle 
    else if(a + b == c || b + c == a || c + a == b)
        return 1;                           //right triangle
    else if(a + b < c || b + c < a || c + a < b)
        return 2;                           //obtuse triangle
    else
        return 3;                           //acute triangle
    
    
}
