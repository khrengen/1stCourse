#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "student.h"
#include "io.c"


int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stdout, "Usage:\n\t./generate FILE_FROM FILE_TO\n");
		exit(0);
	}

	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");
	FILE *add = fopen(argv[1], "a");

	if (!in || !out || !add) {
		fprintf(stderr, "I/O Error: can`t open file.\n");
		exit(1);
	}

	Student s;
	int y,n;

	printf("Add somebody? (1/0)\n");
	scanf("%d", &y);
	if (y == 1){
		printf("How mamy student?\n");
		scanf("%d", &n);
		for (int i = 0; i < n; i++){

			group_read_txt(&s, stdin);
			group_writeadd_txt(&s, add);

		}	
	fclose(add);
	}

	while (group_read_txt(&s,in)){
		group_write_bin(&s, out);

	}
	
	

	

	fclose(in);
	fclose(out);


	return 0;
}