#include"heap.h"
#include <stdlib.h>
int compare(const void *a, const void *b){
    if (*((int *)a) > *((int *)b))
        return -1;
    else if (*((int *)a) < *((int *)b))
        return 1;
    else 
        return 0;
}
void initialize(struct Heap *heap){
    for(int i = 0; i < MAXHEAP; i++)
        heap->ary[i] = 0;
    heap->num = 0;
}
int removeMin(struct Heap *heap){
    int temp = heap->ary[heap->num - 1];
    heap->ary[heap->num - 1] = 0;
    heap->num--;
    return temp;
}
void add(struct Heap *heap, int i){
    heap->ary[heap->num] = i;
    heap->num++;
    qsort(heap->ary, heap->num, sizeof(int), compare);
}
int isFull(struct Heap *heap){
    return heap->num == MAXHEAP;
}
int isEmpty(struct Heap *heap){
    return heap->num == 0;
}
