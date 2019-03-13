#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
extern int is_modify;
void modify_node_by_name(Link head, char name[8]){
	Link p = search_node_by_name(head, name);
	if(p == NULL){
		printf("没有此联系人\n");
	}else{
		printf("输入联系人的新信息：\n");
		give_node_data(p);
		is_modify = 1;
	}

}

