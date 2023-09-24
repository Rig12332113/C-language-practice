#include "activity.h"
#include <stdlib.h>
#include <stdio.h>
int compare(const void *a, const void *b){
    if (((Activity *)a)->start > ((Activity *)b)->start)
        return 1;
    else if (((Activity *)a)->start < ((Activity *)b)->start)
        return -1;
    if (((Activity *)a)->end < ((Activity *)b)->end)
        return 1;
    else if (((Activity *)a)->end > ((Activity *)b)->end)
        return -1;
    else
        return 0;

}

int pick(Activity activities[], int time, int n, Activity *answer, int *num){
    if (n <= 0)
        return 0;
    int take = pick(&activities[1], activities->end, n - 1, answer, num) + 1;
    int nottake = pick(&activities[1], time, n - 1, answer, num);
    if (time > activities->start)
        return nottake;
    else{
        return take > nottake ? take : nottake;
    }
}
int select(Activity activities[], int n){
    Activity *answer = (Activity *)malloc(sizeof(Activity) * n);
    int num = 0;
    qsort(activities, n, sizeof(Activity), compare);
    return pick(activities, 0, n, answer, &num);
}
 
