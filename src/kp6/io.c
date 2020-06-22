#include <stdio.h>
#include <stdlib.h>

#include "student.h"
int group_read_txt(Student *s, FILE *f)
{
	fscanf(f, "%s", s->surname);
	fscanf(f, "%u", &s->num_proc);
	fscanf(f, "%s", s->type_proc);
	fscanf(f, "%u", &s->V_memory);
	fscanf(f, "%s", s->type_video);
	fscanf(f, "%u", &s->V_videomem);
	fscanf(f, "%s", s->type_vin);
	fscanf(f, "%u", &s->num_vin);
	fscanf(f, "%u", &s->V_vin);
	fscanf(f, "%u", &s->num_controler);
	fscanf(f, "%u", &s->num_outside);
	fscanf(f, "%s", s->oper_sys);
	return !feof(f);

}

int group_read_bin(Student *s, FILE *f)
{
    fread(&s->surname, sizeof(s->surname[0]), STR_SIZE, f);
	fread(&s->num_proc, sizeof(s->num_proc), 1, f);
	fread(&s->type_proc, sizeof(s->type_proc[0]), STR_SIZE, f);
	fread(&s->V_memory, sizeof(s->V_memory), 1, f);
	fread(&s->type_video, sizeof(s->type_video[0]), STR_SIZE, f);
	fread(&s->V_videomem, sizeof(s->V_videomem), 1, f);
	fread(&s->type_vin, sizeof(s->type_vin[0]), STR_SIZE, f);
	fread(&s->num_vin, sizeof(s->num_vin), 1, f);
	fread(&s->V_vin, sizeof(s->V_vin), 1, f);
	fread(&s->num_controler, sizeof(s->num_controler), 1, f);
	fread(&s->num_outside, sizeof(s->num_outside), 1, f);
	fread(&s->oper_sys, sizeof(s->oper_sys[0]), STR_SIZE, f);

	return !feof(f);

}

void group_write_bin(Student *s, FILE *f)
{
	fwrite(&s->surname, sizeof(s->surname[0]), STR_SIZE, f);
	fwrite(&s->num_proc, sizeof(s->num_proc), 1, f);
	fwrite(&s->type_proc, sizeof(s->type_proc[0]), STR_SIZE, f);
	fwrite(&s->V_memory, sizeof(s->V_memory), 1, f);
	fwrite(&s->type_video, sizeof(s->type_video[0]), STR_SIZE, f);
	fwrite(&s->V_videomem, sizeof(s->V_videomem), 1, f);
	fwrite(&s->type_vin, sizeof(s->type_vin[0]), STR_SIZE, f);
	fwrite(&s->num_vin, sizeof(s->num_vin), 1, f);
	fwrite(&s->V_vin, sizeof(s->V_vin), 1, f);
	fwrite(&s->num_controler, sizeof(s->num_controler), 1, f);
	fwrite(&s->num_outside, sizeof(s->num_outside), 1, f);
	fwrite(&s->oper_sys, sizeof(s->oper_sys[0]), STR_SIZE, f);


}

void group_write_txt(Student *s, FILE *f)
{
	fprintf(stdout,"%s ",s->surname);
	fprintf(stdout,"%u ",s->num_proc);
	fprintf(stdout,"%s ",s->type_proc);
	fprintf(stdout,"%u ",s->V_memory);
	fprintf(stdout,"%s ",s->type_video);
	fprintf(stdout,"%u ",s->V_videomem);
	fprintf(stdout,"%s ",s->type_vin);
	fprintf(stdout,"%u ",s->num_vin);
	fprintf(stdout,"%u ",s->V_vin);
	fprintf(stdout,"%u ",s->num_controler);
	fprintf(stdout,"%u ",s->num_outside);
	fprintf(stdout,"%s\n",s->oper_sys);
}

void group_writeadd_txt(Student *s, FILE *f)
{
	fprintf(f,"%s ",s->surname);
	fprintf(f,"%u ",s->num_proc);
	fprintf(f,"%s ",s->type_proc);
	fprintf(f,"%u ",s->V_memory);
	fprintf(f,"%s ",s->type_video);
	fprintf(f,"%u ",s->V_videomem);
	fprintf(f,"%s ",s->type_vin);
	fprintf(f,"%u ",s->num_vin);
	fprintf(f,"%u ",s->V_vin);
	fprintf(f,"%u ",s->num_controler);
	fprintf(f,"%u ",s->num_outside);
	fprintf(f,"%s\n",s->oper_sys);
}