#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void delete_node_by_name(Link head, char name[8]){
	is_link_exits(head);
	Link q = head;
	Link p = head->next;
	while(p != NULL){

		if(strcmp(p->name,name) == 0){

			printf("%s---删除的记录为:\n",p->name);
			display_node(p);
			q->next = p->next;
			return;
		}
		q = p;
		p = p->next;
	}
	printf("没有姓名为%s的记录！\n",name);

}
