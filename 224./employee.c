#include "employee.h"
#include <stdlib.h>
#include <string.h>
void init_storage(Employee **storage, int n){
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
void free_storage(Employee **storage){
    free(*storage);
}
Employee* find_employee_by_id(Employee *set, int n, int id ){
    for(int i = 0; i < n; i++){
        if ((set + i)->id == id)
            return (set + i);
    }
}
Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name ){
    for(int i = 0; i < n; i++){
        if (strcmp((set + i)->first_name, first_name) == 0 && strcmp((set + i)->last_name, last_name) == 0)
            return (set + i);
    }
}
Employee* find_root_boss(Employee *set, int n, Employee *employee){
    Employee *temp = employee;
    while(temp->id != temp->boss_id){
        temp = find_employee_by_id(set, n, temp->boss_id);
    }
    return temp;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *temp = B;
    while(temp->id != temp->boss_id){
        if (A->id == temp->boss_id)
            return 2;
        else
            temp = find_employee_by_id(set, n ,temp->boss_id);
    }
    temp = A;
    while(temp->id != temp->boss_id){
        if (B->id == temp->boss_id)
            return 1;
        else
            temp = find_employee_by_id(set, n ,temp->boss_id);
    }
    if (find_root_boss(set, n, A)->id == find_root_boss(set, n ,B)->id)
        return 3;
    else 
        return 0;
}
 
