#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
Node *put(int index, int *array, int n){
    if (index > n - 1)
        return NULL;
    else {
        Node *root = (Node *)malloc(sizeof(Node));
        root->label = array[index];
        root->left = put(2 * index + 1, array, n);
        root->right = put(2 * index + 2, array, n);
        return root;
    }
}
Node *construct(int array[], int n){
    int index = 0;
    return put(index, array, n);
}