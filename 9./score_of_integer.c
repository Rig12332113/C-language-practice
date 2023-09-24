#include<stdio.h>

int main(){
    int input = 0;
    int score = 0;
    scanf("%d", &input);
    if (input <= 0)
        score = -100;
    else{ 
        if (!(input % 3))
        score = score + 3;
        if (!(input % 5))
        score = score + 5;

        if (input >= 100 && input <= 200)
        score = score + 50;
        else
        score = score -50;
    }
    printf("%d\n", score);

    return 0;
}