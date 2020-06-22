#include "table.h"

void    table_create(Table *t)
{
    vector_double_create(&t->keys);
    vector_str_create(&t->data);
}

void	table_destroy(Table *t)
{
    vector_double_destroy(&t->keys);
    vector_str_destroy(&t->data);
}




//void ShellSort(Table *t)             
//{
//	int size = vector_float_length(&t->keys);
//	int step, i, j; 
//	float temp;
//	char *pmet;
//	for (step = size / 2; step > 0; step /= 2) {       
//		for (i = step; i < size; i++) {               
//			for (j = 0; j < i; j++) {                
//				if (t->keys.data[j] > t->keys.data[i]) {            
//					temp = t->keys.data[j];
//					t->keys.data[j] = t->keys.data[i];
//					t->keys.data[i] = temp;
//
//					pmet = t->data.data[j];
//					t->data.data[j] = t->data.data[i];
//					t->data.data[i] = pmet;
//
//				}
//			}
//		}
//	}
//}

void ShellSort(Table *t)
{
    int size = vector_double_length(&t->keys);
    int step, k;
    double temp;
    char* pmet;

    step = size / 2;
    while(step > 0){
        k = 1;
        while (k == 1){
            k = 0;
            for(int i = 0; i < size - step; i++){
                if (t->keys.data[i] > t->keys.data[i + step]){
                    temp = t->keys.data[i];
                    t->keys.data[i] = t->keys.data[i + step];
                    t->keys.data[i + step] = temp;

                    pmet = t->data.data[i];
                    t->data.data[i] = t->data.data[i + step];
                    t->data.data[i + step] = pmet;
                    k = 1;
                }
            }
        }
        step /= 2;
    }
}


int     table_entry_read(Table *t, FILE *f)
{
    double key;
    char val[10000];
    char buf[10000];

    bzero(buf, 10000);
    bzero(val, 10000);
    if (fgets(buf, 10000, f) == NULL)
        return -1;
    key = atof(buf);
    bzero(buf, 10000);
    while (fgets(buf, 10000, f)) {
        if (strcmp(buf, "\n") == 0)
            break;
        strcat(val, buf);
        bzero(buf, 10000);
    }
    vector_double_pushback(&t->keys, key);
    vector_str_pushback(&t->data, val);
    return 1;
}

void     table_read(Table *t, FILE *f)
{
    int n;

    do {
        n = table_entry_read(t, f);
    } while (n != -1);
}


void	table_print(Table *t)
{
    for (int i = 0; i < vector_double_length(&t->keys); ++i) {
        printf( "%f %s\n", vector_double_at(&t->keys, i), vector_str_at(&t->data, i));
    }
}



char	*table_binary_search(Table *t, double key)
{
    double eps = 7.0/3.0 - 4.0/3.0 - 1.0; 
    double left = -1,
        right = vector_double_length(&t->keys);
       double middle;
       int k = 0;
    while (left < right && abs(left - right) > eps) {
        middle = (right + left) / 2;
        if (vector_double_at(&t->keys, middle) <= key)
            left = middle;
        else
            right = middle;
    }
    if (vector_double_at(&t->keys, left) != key)
        return NULL;
    return vector_str_at(&t->data, left);
}