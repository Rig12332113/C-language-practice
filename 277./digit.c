#include<stdio.h>
#include<string.h>
void print(char c,int width, int height, int row, 
           char *horizontal, char *d_vertical, char *l_vertical, char *r_vertical, char *space);
int main(void){
    char string[10] = {};
    char horizontal[9] = {' '}, d_vertical[9],l_vertical[9], r_vertical[9], space[9];
    int height = 0, width = 0;
    while(scanf("%s %d %d", string, &width, &height) != EOF){
        for(int i = 0; i < height; i++){
            for(int j = 0; j < strlen(string); j++){
                print(string[j], width, height, i, horizontal, d_vertical, l_vertical, r_vertical, space);
            }
            printf("\n");
        }
    }
    return 0;
}
char *form_line(char c, int width, int type, char *horizontal, char *d_vertical, 
                char *l_vertical, char *r_vertical, char *space){ 
    
    //橫線
    if (type == 0){
        for(int i = 0; i < width - 2; i++)
            *(horizontal + 1 + i) = c;
        horizontal[width-2] = ' ';
        horizontal[width-1] = '\0';
        return horizontal;
    }
    //雙直線
    else if (type == 1){
        d_vertical[0] = c;
        for(int i = 0; i < width - 2; i++)
            *(d_vertical + 1 + i) = ' ';
        d_vertical[width-2] = c;
        d_vertical[width-1] = '\0';  
        return d_vertical;
    }
    //空白  
    else if (type == 2){
        for(int i = 0; i < width - 1; i++)
            space[i] = ' ';
        space[width-1] = '\0';
        return space;
    }
    //左直線
    else if (type == 3){
        l_vertical[0] = c;
        for(int i = 0; i < width - 2; i++)
            *(l_vertical + 1 + i) = ' ';
        l_vertical[width-1] = '\0';
        return l_vertical;
    }

    //右直線
    else if (type == 4){
        for(int i = 0; i < width - 1; i++)
            *(r_vertical + i) = ' ';
        r_vertical[width-2] = c;
        r_vertical[width-1] = '\0';
        return r_vertical;
    }
}


void print(char c, int width, int height, int row, 
           char *horizontal, char *d_vertical, char *l_vertical, char *r_vertical, char *space){
    switch(c){
        case '0':
        if (row == 0 || row == height - 1)
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '1':
        if (row == 0 || row == height - 1)
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '2':
        if (row == 0 || row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 3, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '3':
        if (row == 0 || row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '4':
        if (row == 0 || row == height - 1)
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));    
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '5':
        if (row == 0 || row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 3, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '6':
        if (row == 0 || row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 3, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '7':
        if (row == 0)
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '8':
        if (row == 0 || row == height - 1 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        break;
        case '9':
        if (row == 0 || row == ((height - 1) / 2))
            printf("%s ", form_line(c, width, 0, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row > 0 && row < ((height - 1) / 2))
            printf("%s ", form_line(c, width, 1, horizontal, d_vertical, l_vertical, r_vertical, space));
        else if (row == height - 1)
            printf("%s ", form_line(c, width, 2, horizontal, d_vertical, l_vertical, r_vertical, space));
        else
            printf("%s ", form_line(c, width, 4, horizontal, d_vertical, l_vertical, r_vertical, space));    
    }
}