#include<stdio.h>
#include "node.h"
struct node *getNode(struct node *head, unsigned int i){
    int index = 0;
    struct node *answer = head;
    while (answer->next != NULL){
        index++;
        answer = answer->next;
    }
    if (i > index)
        return NULL;
    else{
        answer = head;
        for(int j = 0; j < index - i; j++)
            answer = answer->next;
        return answer;
    }
    
}