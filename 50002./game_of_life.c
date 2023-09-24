#include<stdio.h>
#include<stdbool.h>
void game(int map[100][100], int next[100][100], int size){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            int count = 0;
            for(int dx = -1; dx <= 1; dx++)
                for(int dy = -1; dy <= 1; dy++)
                    if (!(dx == 0 && dy == 0)){
                        int x = i + dx;
                        int y = j + dy;
                        if(x >= 0 && x < size && y >= 0 && y < size && map[x][y] == 1)
                        count++;
                    }
            if(map[i][j] == 0 && count == 3)
                next[i][j] = 1;
            else if (map[i][j] == 1 && (count == 2 || count == 3))
                next[i][j] = 1;
            else 
                next[i][j] = 0;
        }    
}
int main(void){
    //輸入
    int size = 0, time = 0;
    scanf("%d%d", &size, &time);
    int map[100][100], next[100][100];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            scanf("%d", &map[i][j]);
    //轉換
    int alive[100][100] = {0};
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if (map[i][j] == 1)
                alive[i][j]++;
    while(time > 0){
        game(map, next, size);
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++){
                map[i][j] = next[i][j];
                if (map[i][j] == 1)
                    alive[i][j]++;
            }
        time--;
    }
    //列印
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if (j == size - 1)
                printf("%d\n", map[i][j]);
            else
                printf("%d ", map[i][j]);
                
    bool valid = 1;
    for(int k = 11; k >= 0 && valid; k--)
        for(int i = size - 1; i >= 0 && valid; i--)
            for(int j = size - 1; j >= 0 && valid; j--)
                if(alive[i][j] == k){
                    valid = 0;
                    printf("%d %d", i + 1, j + 1);
                }
    return 0;
}