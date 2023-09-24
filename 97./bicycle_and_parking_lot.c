#include<stdio.h>
#include<stdlib.h>
int main(void){
    //資料輸入
    int num_park = 0;
    scanf("%d", &num_park);
    int park_x[10] = {0}, park_y[10] = {0}, volume[10] = {0};
    for(int i = 0; i < num_park; i++)
        scanf("%d%d%d", &park_x[i], &park_y[i], &volume[i]);
    long int num_bike = 0;
    scanf("%ld", &num_bike);
    int bike_x[100002] = {0}, bike_y[100002] = {0}; 
    for(int i = 0; i < num_bike; i++)
        scanf("%d%d", &bike_x[i], &bike_y[i]);

    //分配車輛
    int count[10] = {0};
    for(long int i = 0; i < num_bike; i++){
        int distance = 50000, nearest = 0;
        for(int j = 0; j < num_park; j++){
            if (abs(bike_x[i] - park_x[j]) + abs(bike_y[i] - park_y[j]) < distance && count[j] < volume[j]){
                nearest = j;
                distance = abs(bike_x[i] - park_x[j]) + abs(bike_y[i] - park_y[j]);
            }
            else if (abs(bike_x[i] - park_x[j]) + abs(bike_y[i] - park_y[j]) == distance && count[j] < volume[j]){
                if (park_x[j] < park_x[nearest])
                    nearest = j;
                else if (park_x[j] == park_x[nearest])
                    if (park_y[j] < park_y[nearest])
                        nearest = j;           
            }
        }
        count[nearest]++;
    }

    //輸出
    for(int i = 0; i < num_park; i++)
        printf("%d\n", count[i]);
    return 0; 
}