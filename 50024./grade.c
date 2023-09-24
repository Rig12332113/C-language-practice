#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *ptr1, const void *ptr2){
    return (strcmp((char *)ptr1, (char *)ptr2));
}

int main(void){
    int q_num = 0, correct = 0, wrong = 0;
    scanf("%d%d%d", &q_num, &correct, &wrong);
    char ans[50][6];
    for (int i = 0; i < q_num; i++){
        scanf("%s", ans[i]);
        for(int m = 0; m < strlen(ans[i]); m++){
            ans[i][m] = toupper(ans[i][m]);
            qsort(ans[i], strlen(ans[i]), sizeof(char), compare);
        }
    }
    int s_num = 0, index = 0;
    scanf("%d", &s_num);
    while(index < s_num){
        char s_ans[50][6] = {{'\0'}};
        int grade = 0;
        for (int j = 0; j < q_num; j++){
            scanf("%s", s_ans[j]);
            if (strcmp(s_ans[j], "N/A") == 0)
                continue;
            /*else{
                for(int m = 0; m < strlen(s_ans[j]); m++){
                    s_ans[j][m] = toupper(s_ans[j][m]);
                    qsort(s_ans[j], strlen(s_ans[j]), sizeof(char), compare);
                }
            }
            if (strcmp(ans[j], s_ans[j]) == 0)
                grade += correct;
            else
                grade -= wrong;


            if (j == q_num - 1)
                printf("%s\n", s_ans[j]);
            else
                printf("%s ", s_ans[j]); 
            */
        }  
        if (grade < 0)
            printf("0\n");
        else
            printf("%d\n", grade);
        index++;
        
    }
    return 0;
}