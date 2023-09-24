#include<stdio.h>
#include<stdbool.h>

int main(){
    int num = 0;
        scanf("%d", &num);
        float x[4], y[4];
    while(num > 0){
        scanf("%f %f %f %f %f %f %f %f", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
        int length[4];
        float x_center = (x[0] + x[1] + x[2] + x[3]) / 4;
        float y_center = (y[0] + y[1] + y[2] + y[3]) / 4;
        for(int i = 0; i < 4; i++){
            length[i] = (x[i] - x_center) * (x[i] - x_center) + (y[i] - y_center) * (y[i] - y_center);
        }
        bool lengthEqual = 0;
        int angle90 = 0; 
        
        if(length[0] == length[1] && length[1] == length[2] && length[2] == length[3] && length[0] == length[3])
                lengthEqual = 1;
        
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                if((x[i] - x_center) * (x[j] - x_center) + (y[i] - y_center) * (y[j] - y_center) == 0){
                    angle90++;
                }
            }
        }

        if(lengthEqual && angle90 == 4)
            printf("square\n");
        else if(!lengthEqual && angle90 == 4)
            printf("diamond\n");
        else if(lengthEqual && angle90 != 4)
            printf("rectangle\n");
        else
            printf("other\n");
        num--;
    }
    return 0;
}