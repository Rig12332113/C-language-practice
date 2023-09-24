#include <stdio.h>
#include <stdlib.h>
typedef struct restriction{
    int a, b;
}Restriction;
int check(int *country, Restriction *border, int restrict_num){
    int violate = 0;
    for(int i = 0; i < restrict_num && !violate; i++){
        if (country[border[i].a] == 0 || country[border[i].b] == 0)
            continue;
        else if (country[border[i].a] == country[border[i].b])
            violate = 1;
    }
    return violate;
}
void fillin(int *country,int country_num, int color_num, int index, Restriction *border, int restrict_num){
    while(index >= 0 && index < country_num){
        //printf("current fill in :%d\n", index);
        //for(int i = 0; i < country_num; i++)
            //printf("%d))))\n", country[i]);
        if (country[index] < color_num)
            country[index]++;
        else{
            if (index == 0)
                break;
            else{
                country[index] = 0;
                index--;
                continue;
            }
        }
        while(check(country, border, restrict_num)){
            if (country[index] < color_num)
                country[index]++;
            else{
                country[index] = 0;
                index -= 2;
                break;
            }
        }
        index++;
    }
}
int main(void){
    int country_num = 0, color_num = 0, restrict_num = 0;
    scanf("%d%d%d", &country_num, &color_num, &restrict_num);
    Restriction *border = (Restriction *)malloc(sizeof(Restriction) * restrict_num);
    for(int i = 0; i < restrict_num; i++)
        scanf("%d%d", &border[i].a, &border[i].b);
    int *country = (int *)malloc(sizeof(int) * country_num);
    *country = 0;
    fillin(country, country_num, color_num, 0, border, restrict_num);
    int valid = 1;
    for(int i = 0; i < country_num && valid; i++)
        if (country[i] == 0)
            valid = 0;
    if (valid)
        for(int i = 0; i < country_num; i++)
            printf("%d\n", country[i]);
    else
        printf("no solution.\n");
    return 0;   
}

/*
int valid = 1;
    if (index < 0 || index >= country_num)
        valid = 0;
    if(valid){
        printf("in");
        if (country[index] < color_num)
            country[index] += 1;
        else{
            country[index] = 0;
            fillin(country, country_num, color_num, index - 1, border, restrict_num);
        }
        while(check(country, border, restrict_num)){
            if (country[index] < color_num)
                country[index] += 1;
            else{
                country[index] = 0;
                fillin(country, country_num, color_num, index - 1, border, restrict_num);
            }
        }
        fillin(country, country_num, color_num, index + 1, border, restrict_num);
    }
*/