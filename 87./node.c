#include "node.h"
#include <stdio.h>
struct node *merge(struct node *list1, struct node *list2){
    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    if (list1->value < list2->value){
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else if (list1->value > list2->value){
        list2->next = merge(list1, list2->next);
        return list2;
    }
}
