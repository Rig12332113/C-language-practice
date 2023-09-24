#include <stdio.h>
float GPA = 0;
int print(int score){
    #ifdef HUNDRED
        printf("%d ", score);
        return score;
    #endif
    #ifdef APLUS
        if(score <= 100 && score > 89){
            printf("A+ ");
            GPA += 4.3;
            return 95;
        }
        else if (score <= 89 && score > 84){
            printf("A ");
            GPA += 4.0;
            return 87;
        }
        else if (score <= 84 && score > 79){
            printf("A- ");
            GPA += 3.7;
            return 82;
        }
        else if (score <= 79 && score > 76){
            printf("B+ ");
            GPA += 3.3;
            return 78;
        }
        else if (score <= 76 && score > 72){
            printf("B ");
            GPA += 3.0;
            return 75;
        }
        else if (score <= 72 && score > 69){
            printf("B- ");
            GPA += 2.7;
            return 70;
        }
        else if (score <= 69 && score > 66){
            printf("C+ ");
            GPA += 2.3;
            return 68;
        }
        else if (score <= 66 && score > 62){
            printf("C ");
            GPA += 2.0;
            return 65;
        }
        else if (score <= 62 && score > 59){
            printf("C- ");
            GPA += 1.7;
            return 60;
        }
        else if (score <= 59 && score > 0){
            printf("F ");
            GPA += 0;
            return 50;
        }
    #endif
}
int main(void){
    float score = 0, total = 0, num = 0;
    while(scanf("%f", &score) != EOF){
        total += print(score);
        num++;
    }
    if (GPA != 0){
        printf("%.1f ", GPA / num);
    }
    float ave = total / num;
    printf("%.1f", ave);
    return 0;
}
