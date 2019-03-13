#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
extern int is_modify;
void make_empty(Link head){
	Link p = head->next;
	while(p != NULL){
		head->next = p->next;
		free(p);
		p = p->next;
	}
	is_modify = 1;
}

