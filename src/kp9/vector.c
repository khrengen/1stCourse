#include "vector.h"

void		vector_str_create(vector_str *v)
{
	v->data = (char **)malloc(sizeof(char *) * START_SIZE);
	if (v->data == NULL)
		exit(1);
	v->size = 0;
	v->capacity = START_SIZE;
}

void        vector_str_destroy(vector_str *v)
{
	for (int i = 0; i < vector_str_length(v); ++i) {
		free(vector_str_at(v, i));
		vector_str_at_store(v, i,  NULL);
	}
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}

static void vector_str_resize(vector_str *v, int new_size)
{
	char **new_data;

	new_data = (char **)malloc(sizeof(char *) * new_size);
	for (int i = 0; i < vector_str_length(v); ++i) {
		new_data[i] = strdup(vector_str_at(v, i));
	}
	for (int i = 0; i < vector_str_length(v); ++i) {
		free(vector_str_at(v, i));
		vector_str_at_store(v, i, NULL);
	}
	free(v->data);
	v->data = new_data;
	v->capacity = new_size;
}

void        vector_str_pushback(vector_str *v, char *str)
{
	if (v->size == v->capacity)
		vector_str_resize(v, v->size * 2);
	vector_str_at_store(v, v->size, str);
	v->size++;		
}

void		vector_str_at_store(vector_str *v, int i, char *data)
{
	if (data == NULL)
		v->data[i] = NULL;
	else
		v->data[i] = strdup(data);
}

char		*vector_str_at(vector_str *v, int i)
{
	return v->data[i];
}

int			vector_str_length(vector_str *v)
{
    return v->size;
}

void		vector_str_print(vector_str *v)
{
	for (int i = 0; i < vector_str_length(v); ++i) {
		printf("%s ", vector_str_at(v, i));
	}
}

void		vector_set_to_zero(vector_double *v)
{
	for (int i = 0; i < vector_double_length(v); ++i) {
		vector_double_at_store(v, i, 0);
	}
}

void		vector_double_create(vector_double *v)
{
	v->data = (double *)malloc(sizeof(double) * START_SIZE);
	if (v->data == NULL)
		exit(1);
	v->size = 0;
	v->capacity = START_SIZE;
	vector_set_to_zero(v);
}

void        vector_double_destroy(vector_double *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}

static void	vector_double_resize(vector_double *v, int new_size)
{
	v->data = realloc(v->data, new_size * sizeof(double));
	v->capacity = new_size;
}

void        vector_double_pushback(vector_double *v, double val)
{
	if (v->size == v->capacity)
		vector_double_resize(v, v->size * 2);
	vector_double_at_store(v, v->size, val);
	v->size++;
}

double			vector_double_length(vector_double *v)
{
    return v->size;
}

void		vector_double_at_store(vector_double *v, int i, double data)
{
	v->data[i] = data;
}

double			vector_double_at(vector_double *v, int i)
{
	return v->data[i];
}

void		vector_double_print(vector_double *v)
{
	for (int i = 0; i < vector_double_length(v); ++i) {
		printf("%f ", vector_double_at(v, i));
	}
}