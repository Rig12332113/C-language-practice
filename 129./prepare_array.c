void prepare_array(int buffer[], int *array[], int row, int column[]){
    array[0] = &buffer[0];
    int sum = 0;
    for(int i = 1; i < row; i++){
        sum += column[i-1];
        array[i] = &buffer[sum];  
    }
}