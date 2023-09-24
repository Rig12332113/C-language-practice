#include<stdio.h>
#include<math.h>
int min_ovx = 30000, min_ovy = 30000;
long int overlap(float p1x,float p1y, float p2x, float p2y, float halfwidth1, float halfwidth2, float halfheight1, float halfheight2){
    int ovx;
    if (fabs(p1x - p2x) >= halfwidth1 + halfwidth2)
        ovx = 0;
    else if (fabs(p1x - p2x) < halfwidth1 + halfwidth2 && fabs(p1x - p2x) > fabs(halfwidth1 - halfwidth2))
        ovx = halfwidth1 + halfwidth2 - fabs(p1x - p2x);
    else
        ovx = 2 * (halfwidth1 < halfwidth2 ? halfwidth1 : halfwidth2);
    int ovy;
    if (fabs(p1y - p2y) >= halfheight1 + halfheight2)
        ovy = 0;
    else if (fabs(p1y - p2y) < halfheight1 + halfheight2 && fabs(p1y - p2y) > fabs(halfheight1 - halfheight2))
        ovy = halfheight1 + halfheight2 - fabs(p1y - p2y);
    else
        ovy = 2 * (halfheight1 < halfheight2 ? halfheight1 : halfheight2);

    if (ovx < min_ovx )
        min_ovx = ovx;
    if (ovy < min_ovy)
        min_ovy = ovy;
    return ovx * ovy;
}
int main(void){
    int p1x, p1y, p2x, p2y;
    scanf("%d%d%d%d", &p1x, &p1y, &p2x, &p2y);
    int p3x, p3y, p4x, p4y;
    scanf("%d%d%d%d", &p3x, &p3y, &p4x, &p4y);
    int p5x, p5y, p6x, p6y;
    scanf("%d%d%d%d", &p5x, &p5y, &p6x, &p6y);
    long int area = 0;
    area += (p2x - p1x) * (p2y - p1y);
    //printf("%ld\n", area);
    area += (p4x - p3x) * (p4y - p3y);
    //printf("%ld\n", area);
    area += (p6x - p5x) * (p6y - p5y);
    //printf("%ld\n", area);

    float r1x = (p1x + p2x) / 2.0, r1y = (p1y + p2y) / 2.0;
    float r2x = (p3x + p4x) / 2.0, r2y = (p3y + p4y) / 2.0;
    float r3x = (p5x + p6x) / 2.0, r3y = (p5y + p6y) / 2.0;
    float halfwidth1 = (p2x - p1x) / 2.0, halfheight1 = (p2y - p1y) / 2.0;
    //printf("%f, %f\n", halfwidth1, halfheight1);
    float halfwidth2 = (p4x - p3x) / 2.0, halfheight2 = (p4y - p3y) / 2.0;
    //printf("%f, %f\n", halfwidth2, halfheight2);
    float halfwidth3 = (p6x - p5x) / 2.0, halfheight3 = (p6y - p5y) / 2.0;
    //printf("%f, %f\n", halfwidth3, halfheight3);


    area -= overlap(r1x, r1y, r2x, r2y, halfwidth1, halfwidth2, halfheight1, halfheight2);
    //printf("%ld\n", area);  
    area -= overlap(r2x, r2y, r3x, r3y, halfwidth2, halfwidth3, halfheight2, halfheight3);
    //printf("%ld\n", area);
    area -= overlap(r3x, r3y, r1x, r1y, halfwidth3, halfwidth1, halfheight3, halfheight1);
    //printf("%ld\n", area);

    area += min_ovx * min_ovy;
    printf("%ld", area);
    return 0;
}