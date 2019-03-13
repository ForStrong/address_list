#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void read_file(Link head){
	FILE * fp_read;
	Link new_node;
	create_node(&new_node);
	fp_read = fopen("information","r");
	while(fscanf(fp_read,"%s\t%s\t%s\t%s\t%s\t%s\n"
				,new_node->name,new_node->sex,new_node->birthday
				,new_node->phone,new_node->postcode,new_node->addr)!=EOF){
		insert_node_sort(head,new_node);
		create_node(&new_node);
	}
	fclose(fp_read);
}
