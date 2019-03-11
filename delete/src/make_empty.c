#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void make_empty(Link head){
	Link p = head->next;
	while(p != NULL){

		head->next = p->next;
		free(p);
		p = p->next;
	}
}

