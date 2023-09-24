void snake(const int *ptr_array[100][100], int m){
    const int *data[10000];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            data[i * m + j] = ptr_array[i][j];

    const int *temp;
    for(int i = m * m - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (*data[j] > *data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if (i % 2 == 0)
                ptr_array[i][j] = data[i * m + j]; 
            else 
                ptr_array[i][j] = data[i * m + m - j - 1];
        }
    }    
}