int value(int type, int width, int height, int length){
    //錯誤輸入
    if (type != 79 && type != 47 && type != 29 && type != 82 && type != 26 && type != 22)
        return -1;
    if (width <= 0 || height <= 0 || length <= 0)
        return -2;
    //體積計算
    int side[3] = {width, height, length};
    int volume = 0;
    int min = 10000; 
    for (int i = 0; i < 3; i++){
        if (side[i] < min)
            min = side[i];
    }
    int dmax;
    for (int i = min; i > 0; i--){
        if ((side[0] % i == 0) && (side[1] % i == 0) && (side[2] % i == 0)){
            dmax = i;
            break;
        }
    }       
    volume = (side[0] / dmax) * (side[1] / dmax) * (side[2] / dmax) 
             * (dmax * dmax * dmax) * (dmax * dmax * dmax);
    //總價計算
    switch(type){
        case 79:
            return volume * 30;
        case 47:
            return volume * 10;
        case 29:
            return volume * 4;
        case 82:
            return volume * 5;
        case 26:
            return volume * 3;
        case 22: 
            return volume * 9;   
    }
}
