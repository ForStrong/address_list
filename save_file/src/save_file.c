

#include<stdio.h>
#include"../../include/main.h"

void save_file(Link head){
	Link p;
	p = head->next;
	FILE *fp_write;
	fp_write = fopen("information","w+");
	while(p!=NULL){
		fprintf(fp_write,"%s\t%s\t%s\t%s\t%s\t%s\n"
				,p->name,p->sex,p->birthday,p->phone,p->postcode,p->addr);
		p = p->next;
	}
	fclose(fp_write);
}
