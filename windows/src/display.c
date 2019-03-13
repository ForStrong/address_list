#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void display(Link head){
	is_link_exits(head);
	Link p = head->next;	
	if(p == NULL){
		printf("the link is empty!\n");
		return;
	}
	while(p != NULL){
		printf("姓名：%s\n",p->name);
		printf("性别：%s\n",p->sex);
		printf("生日：%s\n",p->birthday);
		printf("电话：%s\n",p->phone);
		printf("邮政编码：%s\n",p->postcode);
		printf("地址：%s\n",p->addr);
		printf("----------next----------\n");
		p = p->next;
	}
}


