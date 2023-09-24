#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num, level;
}Node;
int compare(const void *a, const void *b){
    if (((Node *)a)->level > ((Node *)b)->level)
        return 1;
    else if (((Node *)a)->level < ((Node *)b)->level)
        return -1;
    else{
        if(((Node *)a)->num > ((Node *)b)->num)
            return 1;
        else if (((Node *)a)->num < ((Node *)b)->num)
            return -1;
        else
            return 0;
    }
}

int main(void){
    int node_num = 0;
    scanf("%d", &node_num);
    Node *data = (Node *)malloc(sizeof(Node) * node_num);
    for(int i = 0; i < node_num; i++)
        scanf("%d%d", &data[i].num, &data[i].level);
    qsort(data, node_num, sizeof(Node), compare);
    int findset = 0;
    scanf("%d", &findset);
    for(int i = 0; i < findset; i++){
        int a = 0, b = 0, temp1 = 0, temp2 = 0, temp3 = 0;
        scanf("%d%d", &a, &b);
        for(int j = 0; j < node_num && (temp2 * temp3 == 0); j++){
            if (((data[j].num > a && data[j].num < b) || (data[j].num < a && data[j].num > b)) && temp1 == 0)
                temp1 = data[j].level;
            else if (data[j].num == a)
                temp2 = data[j].level;
            else if (data[j].num == b)
                temp3 = data[j].level;
        }
        //printf("%d %d %d\n", temp1, temp2, temp3);
        if (temp1 != 0 && temp1 < temp2 && temp1 < temp3)
            printf("%d\n", temp2 + temp3 - 2 * temp1);
        else
            printf("%d\n", abs(temp2 - temp3));
    }
    return 0;
}