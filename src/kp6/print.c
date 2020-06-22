#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "student.h"
#include "io.c"


int main(int argc, char *argv[])
{

	FILE *in = fopen(argv[1], "r");

	if (argc != 2) {
		fprintf(stdout, "Usage:\n\t %s DB_FILE\n",argv[0]);
		exit(0);
	}

	

	if (!in) {
		fprintf(stderr, "I/O Error: can`t open file.\n");
		exit(1);
	}

	Student s;

	while (group_read_bin(&s,in)){
		group_write_txt(&s, stdout);
	}

	fclose(in);

	return 0;
}