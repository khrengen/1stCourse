#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "vector.h"

void Create(vector* v, int sz)
{
	v->size = sz;
	v->data = malloc(sizeof(int) * v->size);
}

bool Empty(vector* v)
{
	return v->size == 0;
}

int size(vector* v)
{
	return v->size;
}

int Load(vector* v, int i)
{
	if((i >= 0) && (i < v->size))
		return v->data[i];
}

void Save(vector* v, int i, int t)
{
	if ((i >= 0) && (i< v->size))
		v->data[i] = t;
}

void Resize(vector* v, int sz)
{
	v->size = sz;
	v-> data = realloc(v->data,sizeof(int) * v->size);
}

void Destroy(vector* v)
{
	free(v->data);
}

void printmas(vector* a, number* b, int count)
{
		for (int i = 0; i < count; i++){
			printf("%d\t %lf, %lf\n",a->data[i], b[i].realV, b[i].unrealV);
		}
}

double distancecal(double realV, double unrealV, number* b, int number)
{
	return sqrt(pow(fabs(realV - b[number].realV), 2) + pow(fabs(unrealV - b[number].unrealV),2));
}

double passreal(number* b, double realV, double unrealV, int i)
{
	return (b[i].realV * realV + b[i].unrealV * unrealV) / (pow(realV, 2) + pow(unrealV, 2));
}

double passunreal(double a, number* b, double realV, double unrealV, int i)
{
	return (realV * b[i].unrealV - a * unrealV) / (pow(realV, 2) + pow(unrealV, 2));
}