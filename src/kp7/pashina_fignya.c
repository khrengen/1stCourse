number* pivet = (number *)malloc(sizeof(number));
	number* povet = (number *)malloc(sizeof(number));
	double* distance = (double *)malloc(sizeof(double));
	int* dnum = (int *)malloc(sizeof(int));
	int* iarr = (int *)malloc(sizeof(int));
	int* jarr = (int *)malloc(sizeof(int));
	int* gm = (int *)malloc(count * sizeof(int));
	int* vm = (int *)malloc(count * sizeof(int));

	

	for (int i = 1; i < count; i++){
		if (distancecal(povet, b, i) < distance[0]){
			dnum[0] = 1;
			iarr = realloc(iarr, dnum[0] * sizeof(int));
			jarr = realloc(jarr, dnum[0] * sizeof(int));
			pivet->realV = b[i].realV;
			pivet->unrealV = b[i].unrealV;
			iarr[0] = gm[i];
			jarr[0] = vm[i];
			distance[0] = distancecal(povet, b, i);
			
		} else if (fabs(distancecal(povet, b, i) - distance[0]) < eps){
			dnum[0]++;
			iarr = realloc(iarr, dnum[0] * sizeof(int));
			jarr = realloc(jarr, dnum[0] * sizeof(int));
			iarr[dnum[0] - 1] = gm[i];
			jarr[dnum[0] - 1] = vm[i];
		}
	}

	for (int i = 0; i < count; i++){
		for(int j = 0; j < dnum[0]; j++){
			if (gm[i] == iarr[j] || vm[i] == jarr[j]){
				b[i].realV = passreal(b, pivet, i);
				b[i].unrealV = passreal(b, pivet, i);
				break;
			}
		}
	}