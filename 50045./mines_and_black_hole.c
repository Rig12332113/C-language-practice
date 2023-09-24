#include<stdio.h>
#include<stdlib.h>
typedef struct point
{
    int x, y, z;
}Point;
int dist(Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}
int main(void){
    Point current, mine, hole;
    scanf("%d%d%d", &current.x, &current.y, &current.z);
    int xm, ym, zm, xb, yb, zb;
    scanf("%d%d%d%d%d%d", &mine.x, &mine.y, &mine.z, &hole.x, &hole.y, &hole.z);
    int num, explode = 0, transport = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int opr;
        scanf("%d", &opr);
        switch(opr){
            case 1:
                current.x += 1;     break;
            case 2:
                current.x -= 1;     break;
            case 3:
                current.y += 1;     break;
            case 4:
                current.y -= 1;     break;
            case 5:
                current.z += 1;     break;
            case 6:
                current.z -= 1;     break;
        }
        if (dist(current, mine) < 10)
            break;
        else if (!transport && dist(current, hole) < 10){
            current.x = hole.x;
            current.y = hole.y;
            current.z = hole.z;
            transport = 1;
        }

        //printf("%d %d %d\n", current.x, current.y, current.z);
        if (i % 5 == 4)
            printf("%d %d %d\n", current.x, current.y, current.z);
    }
    return 0;
}