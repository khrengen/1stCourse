#ifndef _STUDENT_H_
#define _STUDENT_H_

#define STR_SIZE 20

#include <stdint.h>
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

int group_read_txt(Student *s, FILE *f);
int group_read_bin(Student *s, FILE *f);
void group_write_bin(Student *s, FILE *f);
void group_write_txt(Student *s, FILE *f);

#endif 