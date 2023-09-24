#include <stdio.h>

int move(int room[100][100],int place_x, int place_y, int dir_x, int dir_y, int width, int depth){
    int temp_x = dir_x;
    int temp_y = dir_y;
    if (place_x == 0 || place_x == width + 1 || place_y == 0 || place_y == depth + 1)
        return room[place_y][place_x];
    else {
        if (room[place_y][place_x] == 0){
            place_x += dir_x;
            place_y += dir_y;
        }
        else{
            dir_x = -1 * temp_y;
            dir_y = -1 * temp_x;
            place_x += dir_x;
            place_y += dir_y;
        }
        return(move(room, place_x, place_y, dir_x, dir_y, width , depth));
    }   
}
int main(void){
    //輸入
    int width = 0, depth = 0;
    scanf("%d%d", &width, &depth);
    int room[100][100];
    for(int i = 1; i <= depth; i++)
        for(int j = 1; j <= width; j++)
            scanf("%d", &room[i][j]);
    for(int j = 1; j <= width; j++)
        room[0][j] = 2 * width + depth - j;
    for(int j = 1; j <= width; j++)
        room[depth + 1][j] = j - 1;
    for(int i = 1; i <= depth; i++)
        room[i][0] = 2 * width + depth + i - 1;
    for(int i = 1; i <= depth; i++)
        room[i][width + 1] = width + depth - i;
    //計算
    int num = 0;
    int dir_x = 0, dir_y = 0, place_x = 0, place_y = 0;
    while(num < 2 * (width + depth)){
        if (num < width){
            place_x = num + 1;    place_y = depth;
            dir_x = 0;  dir_y = -1;
            printf("%d\n", move(room, place_x, place_y, dir_x, dir_y, width, depth));
        }
        else if (num >= width && num < (width + depth)){
            place_x = width;    place_y = width + depth - num;
            dir_x = -1; dir_y = 0;
            printf("%d\n", move(room, place_x, place_y, dir_x, dir_y, width, depth));
        }
        else if (num >= (width + depth) && num < (2 * width + depth)){
            place_x = 2 * width + depth - num;    place_y = 1;
            dir_x = 0;  dir_y = 1;
            printf("%d\n", move(room, place_x, place_y, dir_x, dir_y, width, depth));
        }
        else{
            place_x = 1;    place_y = num - 2 * width - depth + 1;
            dir_x = 1;  dir_y = 0;
            printf("%d\n", move(room, place_x, place_y, dir_x, dir_y, width, depth));
        }
        num++;
    }  
    return 0;
}