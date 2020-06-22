#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "sortstation.h"

int have_br(List *l){
	Iterator it = list_first(l);
	for(int i = 0; i < list_size(l); i++){
		if (it_fetch(&it)[0] == '('){
			return 1;
		}
		it = *it_next(&it);
	}
	return 0;
}

int is_num(char a)
{
	return ((a - '0') >= 0 && (a - '0') <= 9) ? 1 : 0;
}
int is_alpha(char a)
{
	return (a >= 'a' && a <= 'z') ? 1 : 0;
}
int is_op(char a)
{
	return a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '~' ? 1 : 0;
}
int is_left_a(char a)
{
	return a == '+' || a == '-' || a == '*' || a == '/' ? 1 : 0;
}
int is_right_a(char a)
{
	return a == '^' ? 1 : 0;
}
int op_prior(char a)
{
	if(a == '+' || a == '-') {
		return 1;
	} else if(a == '*' || a == '/') {
		return 2;
	} else if(a == '^') {
		return 3;
	} else if(a == '~') {
		return 999;
	}
	return 0;
}

List StrToRPN(const char* string)
{
	List out;
	List stack;
	list_create(&out);
	list_create(&stack);
	char* str = (char*)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(str, string);
	char tmp[20];
	bzero(tmp, 20);
	char* tmpC;
	char c;
	int num_itr = 0;
	

	for(int i = 0; i < strlen(str); i++) {
		c = str[i];
		if(is_num(c)) {
			tmp[num_itr] = c;
		
			list_insert_after(&out, tmp);
			
		}
		if(is_alpha(c)){
		
				tmp[0] = c;

				list_insert_after(&out, tmp);

		}

		if(c == '(') {
			tmp[0] = c;
			//tmp[1] = '\0';
			list_insert_after(&stack, tmp);
		} else if(c == ')') {
			Iterator it = list_last(&stack);
			
			while(it_fetch(&it)[0] != '(') {
					if(list_size(&stack) == 0){
						printf("input error\n");
						return out;
					}
					tmpC = it_fetch(&it);
					list_insert_after(&out, tmpC);
					list_delete_last(&stack);
					it = list_last(&stack);
					free (tmpC);
				
			}

			list_delete_last(&stack);

	
 	    }else if(is_op(c)) {
 			if (list_size(&stack) != 0 && !have_br(&stack)){
 				Iterator it = list_last(&stack);
 				while (is_op(it_fetch(&it)[0]) &&\
 			 		it_fetch(&it)[0] != c &&\
 			  		((is_left_a(c) && op_prior(c) <= op_prior(it_fetch(&it)[0])) ||\
 			  		(is_right_a(c) && op_prior(c) < op_prior(it_fetch(&it)[0])))) {
 					tmpC = it_fetch(&it);
 					list_insert_after(&out, tmpC);
 					list_delete_last(&stack);
 					it = list_last(&stack);
 					free(tmpC);
 				
 				}

 			}
 				tmp[0] = c;
 				list_insert_after(&stack, tmp);

 		}
 	}

	while (list_size(&stack) != 0) {
		Iterator it = list_last(&stack);
		if (it_fetch(&it)[0] == '(' || it_fetch(&it)[0] == ')') {
			printf("unclosed brake\n");
			exit(1);
		}


		tmpC = it_fetch(&it);
		list_delete_last(&stack);
		list_insert_after(&out, tmpC);
		free(tmpC);
	
	}

 	free(str);
	list_destroy(&stack);
	list_print(&out);

return out;
}
