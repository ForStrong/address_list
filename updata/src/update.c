#include<stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
void update_record(sqlite3 * db){
	int ret;
	char * errmsg;
	char sql[100];
	char name[100];
	char new_name[100];
	char new_phone[100];
	
	printf("请输入要修改人的姓名:\n");
	scanf("%s",name);
	printf("请输入新的姓名:\n");
	scanf("%s",new_name);
	printf("请输入新的号码:\n");
	scanf("%s",new_phone);

	sprintf(sql, "update my_phone_book set name = '%s',phone = '%s' where name='%s';",new_name,new_phone,name);
	ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("delete record fail ! :%s\n",errmsg);
		exit(-1);
	}
}
