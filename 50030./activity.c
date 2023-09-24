#include "activity.h"
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    if (((Activity *)a)->end > ((Activity *)b)->end)
        return 1;
    else if (((Activity *)a)->end < ((Activity *)b)->end)
        return -1;
    else
        return 0;

}
int select(Activity activities[], int n){
    int num = 0, time = 0, index = 0;
    qsort(activities, n, sizeof(Activity), compare);
    for(int i = 0; i < n; i++){
        if (activities[index].start >= time){
            time = activities[index].end;
            num++;
            #ifdef PRINT
                printf("%d %d\n", activities[index].start, activities[index].end);
            #endif
        }
        index++;
    }
    return num;
}