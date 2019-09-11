#ifndef LONGM_LIBRARY_H
#define LONGM_LIBRARY_H

struct dim {
    int size;
    char sign;
    long long int *num;
};

int bigger(struct dim a, struct dim b);

struct dim create(struct dim a, const int *size);

struct dim input(struct dim a);

void output(struct dim c);

void check_size(int* size, struct dim a);

void update_size(struct dim a, const int size);

void fill(struct dim a, const int* size);

struct dim plus(struct dim a, struct dim b, struct dim c, int* size, const long long int digit);

struct dim minus(struct dim a, struct dim b, struct dim c, int* size, const long long int digit);


#endif