#include"subtree.h"
#include <stdio.h>
//不同事情用不同函數做
int check(Node *root, int **label, int k){
    if (root == NULL)
        return 0;
    else{
        int leftfound = check(root->left, label, k);
        int rightfound = check(root->right, label, k);
        if (leftfound && rightfound && root->label != k){
            **label = root->label;
            (*label)++;
            return 1;
        }
        return leftfound || rightfound || root->label == k;
    }
}
int getNode(Node *root, int label[], int k){
    int *lastdata = label;
    check(root, &lastdata, k);
    return lastdata - label;
}
 
