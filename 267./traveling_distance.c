#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x, y;
}Point;
int compare(const void *a, const void *b){
    if (((Point *)a)->x * ((Point *)a)->x + ((Point *)a)->y * ((Point *)a)->y
        > ((Point *)b)->x * ((Point *)b)->x + ((Point *)b)->y * ((Point *)b)->y)
    return 1;
    else if (((Point *)a)->x * ((Point *)a)->x + ((Point *)a)->y * ((Point *)a)->y
            < ((Point *)b)->x * ((Point *)b)->x + ((Point *)b)->y * ((Point *)b)->y)
    return -1;
    else{
        if (((Point *)a)->x > ((Point *)b)->x)
            return 1;
        else if (((Point *)a)->x < ((Point *)b)->x)
            return -1;
        else{
            if (((Point *)a)->y > ((Point *)b)->y)
                return 1;
            else if (((Point *)a)->y < ((Point *)b)->y)
                return -1;
            else 
                return 0;
        }
    }
}
int main(void){
    Point cities[100000];
    int num = 0;
    while(scanf("%d%d", &cities[num].x, &cities[num].y) != EOF)
        num++;
    qsort(cities, num, sizeof(Point), compare);
    long long int distance = 0;
    for(int i = 0; i < num - 1; i++){
        distance += (cities[i].x - cities[i+1].x) * (cities[i].x - cities[i+1].x) + 
        (cities[i].y - cities[i+1].y) * (cities[i].y - cities[i+1].y);
    }
    /*for(int i = 0; i < num; i++){
        printf("%d %d\n", cities[i].x, cities[i].y);
    }*/
    distance += cities[0].x * cities[0].x + cities[0].y * cities[0].y;
    printf("%lld", distance);
    return 0;
}