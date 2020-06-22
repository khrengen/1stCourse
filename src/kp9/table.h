#ifndef _TABLE_
#define _TABLE_
#include "vector.h"

#define SIZE_TABLE 12




typedef struct {
	
	vector_double keys;
	vector_str data;


}Table;


void    table_create(Table *t);
void	table_destroy(Table *t);
void table_read(Table *t, FILE *f);
void table_print(Table *t);
void ShellSort(Table *t);
char	*table_binary_search(Table *t, double key);
#endif