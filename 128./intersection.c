#include"intersection.h"
void intersection(int map[100][100], int result[4]){
    int count = 0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++){
            count = 0;
            if (map[i][j] == 1){
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        int temp_i = i + di;
                        int temp_j = j + dj;
                        if (temp_i >= 0 && temp_i < 100 && temp_j >= 0 && temp_j < 100
                            && (di * dj == 0) && !(di == 0 && dj == 0) && (map[temp_i][temp_j] == 1))
                            count++;
                    }
                }
            }
            if (count == 4)
                result[0]++;
            else if (count == 3)
                result[1]++;
            else if (count == 2){
                if ((i == 0 || i == 99) && (j != 0 && j!= 99)){
                    if (map[i][j-1] != map[i][j+1])
                        result[2]++;
                }
                else if ((j == 0 || j == 99) && (i != 0 && i != 99)){
                    if (map[i-1][j] != map[i+1][j])
                        result[2]++;
                }
                else if ((j == 0 || j == 99) && (i == 0 || i == 99))
                    result[2]++;
                else{
                    if ((map[i][j-1] != map[i][j+1]) && (map[i-1][j] != map[i+1][j]))
                        result[2]++;
                }
            }
            else if (count == 1)
                result[3]++;
        }
}