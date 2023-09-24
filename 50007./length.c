#include<stdio.h>
void init(int length[3]) {
    length[0] = 0;
    length[1] = 0;
    length[2] = 0;
}
void add(int length[3], int i) {
    length[0] = i / 36;
    length[1] = (i / 12) % 3;
    length[2] = i % 12;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int a = lengtha[0] * 36 + lengtha[1] * 12 + lengtha[2];
    int b = lengthb[0] * 36 + lengthb[1] * 12 + lengthb[2];
    int c = a + b;
    init(lengthc);
    add(lengthc, c); 
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int a = lengtha[0] * 36 + lengtha[1] * 12 + lengtha[2];
    int b = lengthb[0] * 36 + lengthb[1] * 12 + lengthb[2];
    int c = a - b;
    init(lengthc);
    add(lengthc, c); 
}