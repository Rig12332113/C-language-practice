#include<stdio.h>
int judge(int up, int down, int left, int right){
    int count = 0;
    if (up)
        count++;
    if (down)
        count++;
    if (left)
        count++;
    if (right)
        count++;
    if (count == 2 && (left != right) && (up != down))
        return 2;
    else if(count == 2)
        return 0;
    else
        return count;
}
int main(){
    int map[102][102];
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            map[i][j] = 0;
        }
    }

    //填入地圖
    int size = 0;
    scanf("%d", &size);
    for(int i = 1; i < size + 1; i++){
        for(int j = 1; j < size + 1; j++){
            scanf("%d", &map[i][j]);
        }
    }

    //判斷類型
    int intersection = 0, T = 0, turn = 0, end = 0, type = 0;
    for(int i = 1; i < size + 1; i++){
        for(int j = 1; j < size + 1; j++){
            type = 0;
            if(map[i][j] == 1)
                type = judge(map[i-1][j], map[i+1][j], map[i][j-1], map[i][j+1]);
            switch(type){
                case 1:
                end++;          break;
                case 2:
                turn++;         break;
                case 3:
                T++;            break;
                case 4:
                intersection++; break;
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n", intersection, T, turn, end);
    return 0;
}