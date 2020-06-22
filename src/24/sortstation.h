#ifndef _DAYK_H_
#define _DAYK_H_

#include <string.h>
#include "list.h"

List StrToRPN(const char*);
int is_op(char a);
int is_num(char a);
int is_alpha(char a);
int have_br(List *l);

#endif