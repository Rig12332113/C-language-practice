#include "polynomial.h"
#include <stdio.h>
void init(Polynomial *poly, int coefficient[], int n){
    for(int i = 0; i < n; i++)
        poly->co[i] = coefficient[i];
    poly->num = n;
}
Polynomial add(Polynomial *poly1, Polynomial *poly2){
    Polynomial poly3;
    if (poly1->num >= poly2->num){
        poly3.num = poly1->num;
        for(int i = 0; i < poly3.num; i++){
            if (i < poly2->num)
                poly3.co[i] = poly1->co[i] + poly2->co[i];
            else
                poly3.co[i] = poly1->co[i];
        }
    }
    else{
        poly3.num = poly2->num;
        for(int i = 0; i < poly3.num; i++){
            if (i < poly1->num)
                poly3.co[i] = poly1->co[i] + poly2->co[i];
            else
                poly3.co[i] = poly2->co[i];
        }
    }
    return poly3;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2){
    Polynomial poly3;
    poly3.num = poly1->num + poly2->num - 1;
    for(int i = 0; i < poly3.num; i++)
        poly3.co[i] = 0;
    for (int i = 0; i < poly1->num; i++){
        for(int j = 0; j < poly2->num; j++){
            poly3.co[i + j] += poly1->co[i] * poly2->co[j];
        }
    }
    return poly3;
}
void print(Polynomial *poly){
    for(int i = poly->num - 1; i >= 0; i--){
        if (i == 1){
            if (poly->co[i] != 0)
                printf("%+dx", poly->co[i]);
        }
        else if (i == 0){
            if (poly->co[i] != 0)
                printf("%+d\n", poly->co[i]);
            else
                printf("\n");
        }
        else{
            if (poly->co[i] != 0)
                printf("%+dx^%d", poly->co[i], i);
        }
    }
        
}