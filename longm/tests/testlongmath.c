//
// Created by Семен on 2019-05-30.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/longmath.h"


int main(){
    long long int digit = (long long int) pow(2, 32);
    int s1 = 100;
    int *size = &s1;

    struct dim a;
    a = create(a, size);

    struct dim b;
    b = create(b, size);

    struct dim c;
    c = create(c, size);

    fill(a, size);
    fill(b, size);

    a = input(a);
    b = input(b);

    printf("a= ");
    output(a);
    printf("b= ");
    output(b);

    c = minus(a, b, c, size, digit);
    printf("c= ");
    output(c);


    return 0;
}