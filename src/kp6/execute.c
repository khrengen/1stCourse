#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#include "student.h"
#include "io.c"


void not_wintel(Student *e)
{
	char intel[] = "intel";
    char windows[] = "windows";
	if ((strcmp(e->type_proc, intel) != 0) || (strcmp(e->oper_sys, windows) !=0))  {
		printf( "%.80s\n",e->surname);

	}
}
int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stdout, "Usage:'%s DB_FILE' to execute\n", argv[0]);
		exit(0);

	}
    
    FILE *f = fopen(argv[1], "r");
    if (!f) {
    	fprintf(stderr, "Error: can`t open file.\n");
    	exit(1);
    }

	Student group_fetched;
	uint32_t group_qty = 0;

	while (group_read_bin(&group_fetched, f)) {
	    not_wintel(&group_fetched);

	}

    return 0;
}