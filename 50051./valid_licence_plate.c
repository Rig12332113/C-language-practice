#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int compare(const void *A, const void *B){
    return strcmp((char *)A, (char *)B);
}
int main(void){
    int times = 0;
    scanf("%d", &times);
    char plate[8];
    char type1[50][8], type2[50][8];
    int index1 = 0, index2 = 0;
    for(int i = 0; i < times; i++){
        scanf("%s", plate);
        int consecutive4 = 0, valid = 1, sum = 0;
        if ((plate[2] != '-' && plate[3] != '-') || (plate[2] == '-' && plate[3] == '-'))
            continue;

        for (int i = 0; i < 7 && valid; i++){
            valid = isalnum(plate[i]) || (plate[i] == '-' && (i == 2 || i == 3));
            if (isdigit(plate[i]))
                sum += plate[i] - '0';
            if (plate[i] == '4' && consecutive4 == 0)
                consecutive4 = 1;
            else if (plate[i] == '4' && consecutive4 == 1)
                valid = 0;
            else 
                consecutive4 = 0;
        }
        if (sum % 7 == 0 || !valid)
            continue;

        for(int i = 0; i < 7 && valid; i++){
            int count = 0;
            for(int j = 0; j < 7; j++){
                if (plate[i] == plate[j])
                    count++;
            }
            if (count > 2)
                valid = 0;
        }
        if (!valid)
            continue;

        if (plate[2] == '-' && valid){
            strcpy(type1[index1], plate);
            index1++;
        }
        else if (plate[3] == '-' && valid){
            strcpy(type2[index2], plate);
            index2++;
        }
    }
    qsort(type1, index1, 8 * sizeof(char), compare);
    qsort(type2, index2, 8 * sizeof(char), compare);
    for(int i = 0; i < index1; i++)
        printf("%s\n", type1[i]);
    for(int i = 0; i < index2; i++)
        printf("%s\n", type2[i]);
    return 0;
}