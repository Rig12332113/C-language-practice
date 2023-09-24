#include<stdio.h>
#include<stdbool.h>
bool move(int puzzle[4][4], int next, int i0, int j0){
    int i, j;
    for(int di = -1; di <= 1; di++)
        for(int dj = -1; dj <= 1; dj++){
            i = i0 + di;
            j = j0 + dj;
            if (i >= 0 && i <= 3 && j >= 0 && j <= 3 && di * dj == 0 && !(di == 0 && dj ==0)){
                if (puzzle[i][j] == next){
                    puzzle[i0][j0] = next;
                    puzzle[i][j] = 0;
                }
            } 
        }
    //檢查
    bool valid = 1;
    for(int i = 0; i < 3 && valid; i++)
        for(int j = 0; j < 4 && valid; j++)
            if (puzzle[i][j] != 4 * i + j + 1)
                valid = 0;
    for(int j = 0; j < 3 && valid; j++)
        if (puzzle[3][j] != 13 + j)
            valid = 0; 
    return valid;    
}


int main(void){
    //輸入
    int puzzle[4][4];
    int i0 = 0, j0 = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            scanf("%d", &puzzle[i][j]);
            if (puzzle[i][j] == 0){
                i0 = i;
                j0 = j;
            }
        }
    //移動
    int next;
    bool valid = 0;
    scanf("%d", &next);
    while(next != 0){
        valid = move(puzzle, next, i0, j0);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if (puzzle[i][j] == 0){
                    i0 = i;
                    j0 = j;
                }        
        if (valid)
            break;
        scanf("%d", &next);
    }
    //輸出
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            if (j == 3)
                printf("%d\n", puzzle[i][j]);
            else
                printf("%d ", puzzle[i][j]);
        }
    printf("%d", valid ? 1 : 0);
    if (valid)
        printf(" %d", next);
    return 0;
}