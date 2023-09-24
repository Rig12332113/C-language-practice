#include <stdio.h>
int main(void){
    int machines = 0, jobs = 0;
    scanf("%d%d", &machines, &jobs);
    int machine[500];
    int job[500][1000];
    for(int i = 0; i < jobs; i++){
        scanf("%d%d", &job[i][0], &job[i][1]);
        for(int j = 2; j < 2 * job[i][1] + 2; j++){
            scanf("%d", &job[i][j]);
        }
    }
    for(int i = 0; i < jobs; i++){
        for(int j = 0; j < 2 * job[i][1] + 2; j++){
            printf("%d ", job[i][j]);
        }
        printf("\n");
    }
    return 0;
}