#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct worker
{
    char lastname[80];
    char firstname[80];
    char ID[80];
    int salary;
    int age;
}Worker;
void print_staff(char field[5][10], int index, int *answer, int answer_num, Worker *staff){
    for(int i = 0; i < answer_num; i++){
        for(int j = 0; j < index; j++){
            if (strcmp(field[j], "lastname") == 0){
                printf("%s", staff[answer[i]].lastname);
            }
            else if (strcmp(field[j], "firstname") == 0){
                printf("%s", staff[answer[i]].firstname);
            }
            else if (strcmp(field[j], "ID") == 0){
                printf("%s", staff[answer[i]].ID);
            }
            else if (strcmp(field[j], "salary") == 0){
                printf("%d", staff[answer[i]].salary);
            }
            else if (strcmp(field[j], "age") == 0){
                printf("%d", staff[answer[i]].age);
            }
            if (j == index - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
}
int main(void){
    int staff_num = 0;
    scanf("%d", &staff_num);
    Worker *staff = (Worker *)malloc(sizeof(Worker) * staff_num);
    for(int i = 0; i < staff_num; i++)
        scanf("%s%s%s%d%d", staff[i].lastname, staff[i].firstname, staff[i].ID, &staff[i].salary, &staff[i].age);
    
    int select_num = 0;
    scanf("%d", &select_num);
    for(int i = 0; i < select_num; i++){
        char dump[7];
        scanf("%s", dump);
        char field[8][10];
        int index = 0;
        char temp[10];
        scanf("%s", temp);
        while(strcmp(temp, "where") != 0){
            strcpy(field[index], temp);
            index++;
            scanf("%s", temp);
        }
        char condition1[10];
        char opr[3];
        char condition2[10];
        scanf("%s%s%s", condition1, opr, condition2);
        int answer[50];
        int answer_num = 0;
        if (strcmp(condition1, "lastname") == 0){
                if (strcmp(opr, "==") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].lastname, condition2) == 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, "!=") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].lastname, condition2) != 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
            }
        else if (strcmp(condition1, "firstname") == 0){
                if (strcmp(opr, "==") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].firstname, condition2) == 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, "!=") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].firstname, condition2) != 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
            }
        else if (strcmp(condition1, "ID") == 0){
                if (strcmp(opr, "==") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].ID, condition2) == 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, "!=") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (strcmp(staff[i].ID, condition2) != 0){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
            }
        else if (strcmp(condition1, "salary") == 0){
                int condition = atoi(condition2);
                if (strcmp(opr, "==") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].salary == condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, ">") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].salary > condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, "<") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].salary < condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
            }
        else if (strcmp(condition1, "age") == 0){
                int condition = atoi(condition2);
                if (strcmp(opr, "==") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].age == condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, ">") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].age > condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
                else if (strcmp(opr, "<") == 0){
                    for(int i = 0; i < staff_num; i++){
                        if (staff[i].age < condition){
                            answer[answer_num] = i;
                            answer_num++;
                        }
                    }
                }
            }
        print_staff(field, index, answer, answer_num, staff);
    }
    return 0;
}