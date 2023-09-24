#include "node.h"
#include <stdio.h>
void print(struct node *root, int *answer, int num){
    if (root->left == NULL && root->right == NULL){
        answer[num] = root->data;
        num++;
        for (int i = 0; i < num; i++){
            if (i == num - 1)
                printf("%d\n", answer[i]);
            else 
                printf("%d ", answer[i]);
        }
    }
    else{
        answer[num] = root->data;
        num++;
        if (root->left != NULL)
            print(root->left, answer, num);
        if (root->right != NULL)
            print(root->right, answer, num);
    }
}
void print_all_paths(struct node *root){
    int answer[1000];
    int num = 0;
    print(root, answer, num);
}
