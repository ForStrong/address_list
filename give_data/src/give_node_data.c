#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void give_node_data(Link new_node){
	printf("输入姓名:\n");scanf("%s",new_node->name);
	printf("输入性别:\n");scanf("%s",new_node->sex);
	printf("输入生日:\n");scanf("%s",new_node->birthday);
	printf("输入电话:\n");scanf("%s",new_node->phone);
	printf("输入邮政编号:\n");scanf("%s",new_node->postcode);
	printf("输入地址:\n");scanf("%s",new_node->addr);

}
