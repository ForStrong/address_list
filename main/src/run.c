#include<stdio.h>
#include"../../include/main.h"
void safe_flush(FILE *fp)
{

	int ch;
	while( (ch = fgetc(fp)) != EOF && ch != '\n' );          
}

int main(){	
	Link head;
	Link new_node;
	Link search_node;
	int flag;
	create_link(&head);
	while(1){
		showMenu();
		char name[8];
loop:printf("请输入代号(1~7): ");
	 scanf("%d",&flag);
	 if(flag < 1 || flag > 7){
		 printf("输入格式有误，请重新输入！\n");
		 safe_flush(stdin);
		 goto loop;
	 }
	 switch(flag){
		 case 1: printf("----------添加联系人----------\n");
				 create_node(&new_node);
				 give_node_data(new_node);
				 insert_node_sort(head, new_node);
				 break;
		 case 2:	printf("输入要查找人的姓名：");
					scanf("%s",&name);
					search_node = search_node_by_name(head, name);
					printf("%s---查找结果为:\n",name);
					if(search_node == NULL)
						printf("没有姓名为%s的联系人\n",name);
					else
						display_node(search_node);
					break;
		 case 3:printf("----------通讯录----------\n");
				display(head);
				break;
		 case 4:printf("输入要修改的联系人姓名：");
				scanf("%s",&name);
				modify_node_by_name(head, name);
				break;
		 case 5:printf("输入要删除人姓名：");
				scanf("%s", &name);
				delete_node_by_name(head, name);
				break;
		 case 6:make_empty(head);
				break;
		 case 7:exit_show();
				exit(0);
				break;
	 }
	safe_flush(stdin);	
	}
	return 0;
}
