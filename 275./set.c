#include "set.h"
void init(Set *set){
    *set = 0;
}
void add(Set *set, int i){
    long long int temp = 1;
    *set = *set | temp << i;
}
void has(Set set, int i){
    long long int temp = 1;
    temp = temp << i;
    if ((set & temp) == temp)
        printf("set has %d\n", i);
    else 
        printf("set does not have %d\n", i);
}
Set setUnion(Set a, Set b){
    return a | b;
}
Set setIntersect(Set a, Set b){
    return a & b;
}
Set setDifference(Set a, Set b){
    return a ^ b;
}