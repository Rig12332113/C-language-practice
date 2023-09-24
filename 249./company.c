#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}Employee;
int staff_num = 0;
int judge_subordinate(Employee *staff, Employee A, Employee B){
    Employee temp;
    if (A.boss_id == B.id){
        printf("subordinate\n");
        return 1;
    }
    else if (A.id == A.boss_id)
        return 0;
    else{
        for(int i = 0; i < staff_num; i++)
            if ((staff + i)->id == A.boss_id){
                temp = *(staff + i);
                break;
            }
        return judge_subordinate(staff, temp, B);
    }
}
int judge_supervisor(Employee *staff, Employee A, Employee B){
    Employee temp;
    if (A.id == B.boss_id){
        printf("supervisor\n");
        return 1;
    }
    else if (B.id == B.boss_id)
        return 0;
    else{
        for(int i = 0; i < staff_num; i++)
            if ((staff + i)->id == B.boss_id){
                temp = *(staff + i);
                break;
            }
        return judge_supervisor(staff, A, temp);
    }
}
int judge_colleague(Employee *staff, Employee A, Employee B){
    Employee tempA = A, tempB = B;
    while(tempA.id != tempA.boss_id){
        for(int i = 0; i < staff_num; i++)
            if ((staff + i)->id == tempA.boss_id)
                tempA = *(staff + i);
    }
    while(tempB.id != tempB.boss_id){
        for(int i = 0; i < staff_num; i++)
            if ((staff + i)->id == tempB.boss_id)
                tempB = *(staff + i);
    }
    if (tempA.id == tempB.id){
        printf("colleague\n");
        return 1;
    }
    return 0;
}
int main(void){
    scanf("%d", &staff_num);
    Employee *staff = (Employee *)malloc(sizeof(Employee) * staff_num);
    for(int i = 0; i < staff_num; i++){
        scanf("%d", &(staff + i)->id);
        scanf("%s", (staff + i)->first_name);
        scanf("%s", (staff + i)->last_name);
        scanf("%d", &(staff + i)->boss_id);
    }
    int cmd_num = 0;
    scanf("%d", &cmd_num);
    for(int i = 0; i < cmd_num; i++){
        char temp_first1[30], temp_last1[30], temp_first2[30], temp_last2[30];
        Employee temp_ID1, temp_ID2;
        int found = 0;
        scanf("%s%s", temp_first1, temp_last1);
        scanf("%s%s", temp_first2, temp_last2);
        for(int i = 0; i < staff_num && found < 2; i++){
            if (strcmp((staff + i)->first_name, temp_first1) == 0 && strcmp((staff + i)->last_name, temp_last1) == 0){
                temp_ID1 = *(staff + i);
                found++;
            }
            else if (strcmp((staff + i)->first_name, temp_first2) == 0 && strcmp((staff + i)->last_name, temp_last2) == 0){
                temp_ID2 = *(staff + i);
                found++;
            }
        }
        int check = 0;
        if (!check)
            check = judge_subordinate(staff, temp_ID1, temp_ID2);
        if (!check)
            check = judge_supervisor(staff, temp_ID1, temp_ID2);
        if (!check)
            check = judge_colleague(staff, temp_ID1, temp_ID2);
        if (!check)
            printf("unrelated\n");
    }
    return 0;
}