#include<stdio.h>
#include"../../include/main.h"
extern int is_modify = 0;

void safe_flush(FILE *fp)
{

	int ch;
	while( (ch = fgetc(fp)) != EOF && ch != '\n' );          
}

void save_file_is(int is_save_line,Link head){
	if(is_save_line == 0){
		return;
	}
	int is_save_file;
	printf("是否要保存到本地文件中(1:保存，0:不保存)!\n");
input:scanf("%d",&is_save_file);
	if(!(is_save_file == 1 || is_save_file == 0)){
		printf("输入格式不对，请重新输入(1:保存,2:不保存)");
		safe_flush(stdin);
		goto input;
	}
	if(is_save_file == 1){
		save_file(head);
		printf("保存成功!\n");
	}else{
		printf("没有保存到文件!\n");
	}
}

int main(){	
	Link head;
	Link new_node;
	Link search_node;
	int flag;
	create_link(&head);
	read_file(head);
	while(1){
		showMenu();
		char name[20];
loop:printf("请输入代号(1~8): ");
	 scanf("%d",&flag);
	 if(flag < 1 || flag > 8){
		 printf("输入格式有误，请重新输入！\n");
		 safe_flush(stdin);
		 goto loop;
	 }
	 switch(flag){
		 case 1: printf("----------添加联系人----------\n");
 				 create_node(&new_node);
				 give_node_data(new_node);
				 insert_node_sort(head, new_node);
				 is_modify = 1;
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
		 case 7:save_file_is(is_modify,head);	
				break;
		 case 8:exit_show();
 				exit(0);
				break;
	 }
	safe_flush(stdin);	
	}
	return 0;
}
