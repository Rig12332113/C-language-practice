#include<stdio.h>
typedef struct vector
{
    int x, y, z;
} Vector;

int main(void){
    Vector a1;
    Vector a2;
    scanf("%d%d%d", &a1.x, &a1.y, &a1.z);
    scanf("%d%d%d", &a2.x, &a2.y, &a2.z);
    printf("%d\n", a1.x * a2.x + a1.y * a2.y + a1.z * a2.z);
    printf("%d %d %d", a1.y * a2.z - a1.z * a2.y, a1.z * a2.x - a1.x * a2.z, a1.x * a2.y - a1.y * a2.x); 
    return 0;
}