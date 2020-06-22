#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main(int argc, char *argv[])
{
	if (argc > 3) {
		fprintf(stdout, "wrong input\n");
		exit(1);
	}

	FILE *in = fopen(argv[1], "r");

	Table t;
	char *res;

	table_create(&t);
	table_read(&t, in);
	//table_print(&t);
	printf("/////////////////////\n");
	ShellSort(&t);  
	//table_print(&t);


	if (argc == 3){
		res = table_binary_search(&t, atof(argv[2]));
		if (res == NULL){
			printf("key not found\n");
		} else printf("YOUR WORD IS: %s\n", res);
	}

	table_destroy(&t);
	fclose(in);
	return 0;
}