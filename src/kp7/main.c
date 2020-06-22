#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "vector.h"


int main(void){

	int count = 0;
	int m,n;

	vector a;
	vector index;



	Create(&a, 1);
	number* arr = (number *)malloc(sizeof(number));
	number* b = (number *)malloc(sizeof(number));

	printf("enter matrix size (m x n)) ");
	scanf("%d%d", &m, &n);

	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n; i++){
			scanf("%lf/%lf", &arr->realV, &arr->unrealV);
			if (arr->realV != 0 || arr->unrealV != 0){
				if (count > 0){
					Resize(&a, count + 1);
					b = realloc(b, (count + 1) * sizeof(number));

				}
				Save(&a, count, (j - 1) * n + i - 1);
				b[count].realV = arr->realV;
				b[count].unrealV = arr->unrealV;
				count++;

			}
		}
		
	}
	if (count == 0){
		printf("only nulls in matrix\n");
		return 1;
	}

	printmas(&a, b, count);

///////////////////////////////////////////////////////////////
	printf("\n");

	double rl, nrl;
	double min = 10000000;
	Create(&index, 1);
	printf("your complex number: ");
	scanf("%lf/%lf", &rl, &nrl);

	double distance;
	for (int i = 0; i < count; i++){
		distance = distancecal(rl, nrl, b, i);

		if (distance < min){
			min = distance;
			Save(&index, 0, i);

		}
	}

	int q = 1;

	for (int i = 0; i < count; i++){
		distance = distancecal(rl, nrl, b, i);
		if ((distance == min) && (i != Load(&index, 0))){
			Resize(&index, q + 1);
			Save(&index, q, i);
			q++;
		}
	}

	rl = b[Load(&index, 0)].realV;
	nrl = b[Load(&index, 0)].unrealV;
	int x,y,z;

	for (int w = 0; w < q; w++){
		z = Load(&a, Load(&index, w));// w от нуля до q
		x = (z / n);
		y = z % n;


		for (int i = 0; i < count; i++){
			if ((Load(&a,i) / n == x) || (Load(&a, i) % n == y)){
				if(Load(&a,i) != z){
					double a = b[i].realV;
					b[i].realV = passreal(b, rl,nrl, i);
					b[i].unrealV = passunreal(a, b, rl, nrl, i);
				}
			}
		}
	}	

	
	printmas(&a, b, count);

	Destroy(&a);
	free(b);
	free(arr);
	Destroy(&index);
	return 0;
}