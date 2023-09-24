#include"employee.h"
#include <string.h>
int relation(Employee *employee1, Employee *employee2){
    Employee *temp1 = employee2;
    while(temp1->boss != temp1){
        if (temp1->boss == employee1)
            return 2;
        else 
            temp1 = temp1->boss;
    }
    Employee *temp2 = employee1;
    while(temp2->boss != temp2){
        if (temp2->boss == employee2)
            return 1;
        else 
            temp2 = temp2->boss;
    }
    if (temp1 == temp2)
        return 3;
    else 
        return 4;
}
