#include<stdio.h>
#include"../address.h"

void menu()
{
	system("clear");
	printf("\n");
	printf("#################          通讯录管理系统  v4.0   ###################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#           1-----------------信息录入-------------------           #\n");		
	printf("#                                                                   #\n");
	printf("#           2-----------------信息删除-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           3-----------------信息修改-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           4-----------------信息查询-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           5-----------------信息显示-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           6-----------------退出系统-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#      POWER BY *************    南京工程学院        2019-03-27     #\n");
	printf("#####################################################################\n");


}

void exit_show(){
	printf("###########          通讯录管理系统  v4.0   ################\n");
	printf("############################################################\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                     谢谢使用！                           #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("#                                                          #\n");
	printf("############################################################\n");
	printf("# POWER BY *************    南京工程学院    2019-03-07     #\n");
	printf("############################################################\n");
}

void main_handler(int fd)
{
	char choice[20]={0};
	while(1)
	{
		menu();
		scanf("%s",choice);
		switch(choice[0])
		{
			case '1':
				add_info(fd);
				break;
			case '2':
				delete_info(fd);
                                break;
			case '3':
				updata_info(fd);
                                break;
			case '4':
				search(fd);
                                break;
			case '5':
				show_info(fd);
                                break;
			case '6':
                                exit_client(fd);
				break;
			default :
				printf("input error...\n");
		}
	}
}
