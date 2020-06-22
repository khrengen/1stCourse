#ifndef _Vector_H_
#define _Vector_H_

typedef struct 
{
	int* data;
	int size;
	
}vector;

void Create(vector* v, int sz);
bool Empty(vector* v);
int size(vector* v);
int Load(vector* v, int i);
void Save(vector* v, int i, int t);
void Resize(vector* v, int sz);
void Destroy(vector* v);

typedef struct 
{
	double realV;
	double unrealV;
	
}number;

void printmas(vector* a, number* b, int count);
double distancecal(double realV, double unrealV, number* b, int number);
double passreal(number* b, double realV, double unrealV, int i);
double passunreal(double a, number* b, double realV, double unrealV, int i);

#endif