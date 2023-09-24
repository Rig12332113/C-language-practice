#include "SpiralSnake.h"
void SpiralSnake(int N, int *snake, int *result){
    int data[1001][1001];
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    int row = N / 2;
    int column = N / 2;
    int direction = 0, index = 0;
    data[row][column] = snake[index];
    index++;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < ((i == N - 1) ? 3 : 2); j++){
            for(int m = 0; m < i; m++){
                row += dr[direction];
                column += dc[direction];
                data[row][column] = snake[index];
                index++;
            }
            direction = ((direction + 1) % 4);
        }
    }
    index = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[index] = data[i][j];
            index++;
        }
    }
}