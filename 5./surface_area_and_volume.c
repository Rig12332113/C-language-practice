#include<stdio.h>
int main(){
    int height = 0, width = 0, depth = 0;
    scanf("%d %d %d", &height, &width, &depth);
    int surfarea = 0, volume = 0;
    printf("%d\n", 2 * (height * width + height * depth + width * depth));
    printf("%d\n", height * width * depth);
    return 0;


}