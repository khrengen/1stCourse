#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//#include "student.h"
//#include "io.h"
#define STR_SIZE 24

typedef struct {
	char surname[STR_SIZE];
	uint32_t num_proc;
	char type_proc[STR_SIZE];
	uint32_t V_memory;
	char type_video[STR_SIZE];
	uint32_t V_videomem;
	char type_vin[STR_SIZE];
	uint32_t num_vin;
	uint32_t V_vin;
	uint32_t num_controler;
	uint32_t num_outside;
	char oper_sys[STR_SIZE];

} Student;

void group_write(Student *e, FILE *f)
{
	fwrite(&e->surname, sizeof(e->surname[0]), STR_SIZE, f);
	fwrite(&e->num_proc, sizeof(e->num_proc), 1, f);
	fwrite(&e->type_proc, sizeof(e->type_proc[0]), STR_SIZE, f);
	fwrite(&e->V_memory, sizeof(e->V_memory), 1, f);
	fwrite(&e->type_video, sizeof(e->type_video[0]), STR_SIZE, f);
	fwrite(&e->V_videomem, sizeof(e->V_videomem), 1, f);
	fwrite(&e->type_vin, sizeof(e->type_vin[0]), STR_SIZE, f);
	fwrite(&e->num_vin, sizeof(e->num_vin), 1, f);
	fwrite(&e->V_vin, sizeof(e->V_vin), 1, f);
	fwrite(&e->num_controler, sizeof(e->num_controler), 1, f);
	fwrite(&e->num_outside, sizeof(e->num_outside), 1, f);
	fwrite(&e->oper_sys, sizeof(e->oper_sys[0]), STR_SIZE, f);

}

void group_read(Student *e, FILE *f)
{
    fread(&e->surname, sizeof(e->surname[0]), STR_SIZE, f);
	fread(&e->num_proc, sizeof(e->num_proc), 1, f);
	fread(&e->type_proc, sizeof(e->type_proc[0]), STR_SIZE, f);
	fread(&e->V_memory, sizeof(e->V_memory), 1, f);
	fread(&e->type_video, sizeof(e->type_video[0]), STR_SIZE, f);
	fread(&e->V_videomem, sizeof(e->V_videomem), 1, f);
	fread(&e->type_vin, sizeof(e->type_vin[0]), STR_SIZE, f);
	fread(&e->num_vin, sizeof(e->num_vin), 1, f);
	fread(&e->V_vin, sizeof(e->V_vin), 1, f);
	fread(&e->num_controler, sizeof(e->num_controler), 1, f);
	fread(&e->num_outside, sizeof(e->num_outside), 1, f);
	fread(&e->oper_sys, sizeof(e->oper_sys[0]), STR_SIZE, f);	
}

char intel[] = "intel";
char windows[] = "windows";

void not_wintel(Student *e)
{
	if ((strcmp(e->type_proc, intel) != 0) || (strcmp(e->oper_sys, windows) !=0))  {
		printf( "%.80s\n",e->surname);
	}
	//printf("%u\n",(unsigned int) e->num_proc);
	//printf("%.80s\n", e->type_proc);
	//printf("%.80s\n",e->oper_sys );
	//...
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stdout, "Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
		exit(0);

	}

	Student group[] = {
		{"Petrin", 5, "intel", 16, "zotac", 32, "vin", 1, 1024, 3, 4, "windows"},
		{"Sin", 112, "huintel", 228, "gforce", 322, "eazy", 500, 501, 505, 606, "linux"},
		{"LOL", 112, "intel", 228, "gforce", 322, "eazy", 500, 501, 505, 606, "windows"},
		{"Genbl4", 5, "intel", 16, "zotac", 32, "vin", 1, 1024, 3, 4, "linux"}
	};
	//printf("%ld\n", sizeof(group));
	//printf("%ld\n",sizeof(Student));
	uint32_t group_qty = sizeof(group) / sizeof(Student);
	FILE *f = NULL;

	if (argv[1][0] == 'w') {
		f = fopen("employees.bin", "w");

		fwrite(&group_qty, sizeof(group_qty), 1, f);
		for (int i = 0; i < group_qty; ++i) {
			group_write(group + i, f);
		}

	} else if (argv[1][0] == 'r') {
		f = fopen("employees.bin", "r");

		Student group_fetched;
		fread(&group_qty, sizeof(group_qty), 1, f);
		for (int i = 0; i < group_qty; ++i) {
			group_read(&group_fetched, f);
			not_wintel(&group_fetched);


		}	

	} else {
		fprintf(stderr, "Usage: '%s w' to write, '%s r' to read\n", argv[0], argv[0]);
		exit (2);
	}
    return 0;
}
