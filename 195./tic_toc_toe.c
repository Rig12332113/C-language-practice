#include<stdio.h>
#define DRAW 0
#define BLACK 1
#define WHITE 2
int check(int grid[3][3]){
    for(int i = 1; i < 3; i++){
        if (grid[0][0] == i && grid[0][1] == i && grid[0][2] == i)
            return i;
        else if (grid[1][0] == i && grid[1][1] == i && grid[1][2] == i)
            return i;
        else if (grid[2][0] == i && grid[2][1] == i && grid[2][2] == i)
            return i;
        else if (grid[0][0] == i && grid[1][0] == i && grid[2][0] == i)
            return i;
        else if (grid[0][1] == i && grid[1][1] == i && grid[2][1] == i)
            return i;
        else if (grid[0][2] == i && grid[1][2] == i && grid[2][2] == i)
            return i;
        else if (grid[0][0] == i && grid[1][1] == i && grid[2][2] == i)
            return i;
        else if (grid[0][2] == i && grid[1][1] == i && grid[2][0] == i)
            return i;  
    }
    return 0;
}
int main(void){
    int grid[3][3] = {{0}};
    int num = 0, valid_count = 0, win = 0;
    scanf("%d", &num);
    int x[1000] = {0}, y[1000] = {0};
    for (int i = 0; i < num; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 0; i < num; i++){
        int x_temp = x[i], y_temp = y[i];
        if(x_temp >= 0 && x_temp <= 2 && y_temp >= 0 && y_temp <= 2 && grid[x_temp][y_temp] == 0){
            valid_count++;
            if(valid_count % 2 == 1)
                grid[x_temp][y_temp] = BLACK;
            else
                grid[x_temp][y_temp] = WHITE;
            win = check(grid); 
        }
        if (win != 0)
            break;
    }
    switch(win){
        case DRAW:
            printf("There is a draw.\n");  break;
        case BLACK:
            printf("Black wins.\n");       break;
        case WHITE:
            printf("White wins.\n");       break;
    }
    return 0;
}