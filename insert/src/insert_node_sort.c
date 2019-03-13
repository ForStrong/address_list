#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert_node_sort(Link head, Link new_node){
	is_link_exits(head);
	Link p = head->next;
	Link q = head;
	while(p != NULL){
		if(strcmp(p->name,new_node->name)>0){
			q->next = new_node;
			new_node->next = p;
			return;
		}
		q = p;
		p = p->next;
	}
	q->next = new_node;
	new_node->next = NULL;

}

