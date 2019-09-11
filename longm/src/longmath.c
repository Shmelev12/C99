#include "../headers/longmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int bigger(struct dim a, struct dim b){
    for (int i = a.size > b.size?a.size - 1:b.size - 1; i >= 0; i--){
        if (a.num[i] > b.num[i]) {
            return 1;
        } else if (a.num[i] < b.num[i]) {
            return 0;
        }
    }

    return -1;
}

struct dim create(struct dim a, const int *size) {
    a.num = (long long int*)malloc(sizeof(long long int) * *size);
    a.size = 0;
    a.sign = '+';

    return a;
}

struct dim input(struct dim a){
    int n = 0;
    scanf("%d", &n);
    a.size = n;
    int first = 1;
    for (int i = n - 1; i >= 0; i--){
        long long int b = 0;
        scanf("%lld", &b);
        if (first == 1 && b < 0){
            first = 0;
            a.sign = '-';
            b = b * -1;
        }
        a.num[i] = b;
    }

    return a;
}

void output(struct dim c){
    for(int i = c.size - 1; i >=0 ; i--) {
        if (c.num[i] != 0) {printf("%c %lld * 2**%d ",c.sign, c.num[i] , 32 * i);}
    }
    if (c.size == 0) {
        printf("0");
    }
    printf("\n");
}

void check_size(int* size, struct dim a){*size = a.size == *size?*size * 2:*size;}

void update_size(struct dim a, const int size){a.num =  (long long int*)realloc(a.num, sizeof(long long int) * size);}

void fill(struct dim a, const int* size){ for (int i = a.size; i < *size; i++) {a.num[i] = 0;}}

struct dim plus(struct dim a, struct dim b, struct dim c, int* size, const long long int digit){
    if (a.sign == b.sign) {
        if (a.sign == '-') {
            c.sign = '-';
        } else {
            c.sign = '-';
        }
    } else {
        if (bigger(a, b) == 1 && a.sign == '-') {
            c.sign = '-';

            long long int current_digit = 0;
            long long int next_rank = 0;
            int bool = 0;

            for(int i = 0; i < *size; i++){
                if (a.num[i] == 0 && b.num[i] == 0 && next_rank == 1){
                    bool++;
                }
                current_digit = a.num[i] - b.num[i] - next_rank;
                next_rank = current_digit < 0?1:0;
                c.num[i] = next_rank == 1?current_digit + digit:current_digit;
            }

            c.size = a.size > b.size?a.size:b.size;
            if (bool != 0){c.size++;};

            return c;

        } else if (bigger(b, a) == -1) {
            for (int i = 0; i < *size; i++) {
                c.num[i] = 0;
            }
            return c;
        } else if (bigger(b, a) == 1 && b.sign == '-') {
            c.sign = '-';

            struct dim buff = a;
            a = b;
            b = buff;

            long long int current_digit = 0;
            long long int next_rank = 0;
            int bool = 0;

            for(int i = 0; i < *size; i++){
                if (a.num[i] == 0 && b.num[i] == 0 && next_rank == 1){
                    bool++;
                }
                current_digit = a.num[i] - b.num[i] - next_rank;
                next_rank = current_digit < 0?1:0;
                c.num[i] = next_rank == 1?current_digit + digit:current_digit;
            }

            c.size = a.size > b.size?a.size:b.size;
            if (bool != 0){c.size++;};

            return c;
        }

    }
    check_size(size, a);
    check_size(size, b);
    update_size(a, *size);
    update_size(b, *size);
    fill(a, size);
    fill(b, size);

    long long int current_digit = 0;
    long long int next_rank = 0;
    int bool = 0;


    for(int i = 0; i < *size; i++){
        if (a.num[i] == 0 && b.num[i] == 0 && next_rank == 1){
            bool++;
        }
        current_digit = a.num[i] + b.num[i] + next_rank;
        next_rank = current_digit >= digit?1:0;
        c.num[i] = next_rank == 1?current_digit - digit:current_digit;
    }

    c.size = a.size > b.size?a.size:b.size;
    if (bool != 0){
        c.size++;
    };

    return c;
}

struct dim minus(struct dim a, struct dim b, struct dim c, int* size, const long long int digit){
    if (a.sign != b.sign) {
        if (a.sign == '-'){
            c.sign = '-';
        }

        return plus(a, b, c, size, digit);
    } else {
        if (a.sign == '-' && bigger(a, b) == 1) {
            c.sign = '-';
        } else if (bigger(b, a) == 1) {
            struct dim buff = a;
            a = b;
            b = buff;
        } else if (bigger(a, b) == -1) {
            for (int i = 0; i < *size; i++) {
                c.num[i] = 0;
            }
            return c;
        }
    }

    check_size(size, a);
    check_size(size, b);
    update_size(a, *size);
    update_size(b, *size);
    fill(a, size);
    fill(b, size);

    long long int current_digit = 0;
    long long int next_rank = 0;
    int bool = 0;

    for(int i = 0; i < *size; i++){
        if (a.num[i] == 0 && b.num[i] == 0 && next_rank == 1){
            bool++;
        }
        current_digit = a.num[i] - b.num[i] - next_rank;
        next_rank = current_digit < 0?1:0;
        c.num[i] = next_rank == 1?current_digit + digit:current_digit;
    }

    c.size = a.size > b.size?a.size:b.size;
    if (bool != 0){c.size++;};

    return c;
}