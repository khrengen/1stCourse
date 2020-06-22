#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_SIZE 5

typedef struct {
    char **data;
    int size;
    int capacity;
} vector_str;

typedef struct {
    double *data;
    int size;
    int capacity;
} vector_double;

void        vector_str_create(vector_str *v);
void        vector_str_destroy(vector_str *v);
void        vector_str_pushback(vector_str *v, char *str);
int         vector_str_length(vector_str *v);
char		*vector_str_at(vector_str *v, int i);
void		vector_str_at_store(vector_str *v, int i, char *data);
void		vector_str_print(vector_str *v);

void        vector_double_create(vector_double *v);
void        vector_double_destroy(vector_double *v);
void        vector_double_pushback(vector_double *v, double val);
double         vector_double_length(vector_double *v);
double	        vector_double_at(vector_double *v, int i);
void		vector_double_at_store(vector_double *v, int i, double data);
void		vector_double_print(vector_double *v);

#endif