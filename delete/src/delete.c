#include<stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
void delete_record(sqlite3 * db){
	int ret;
	char * errmsg;
	char sql[100];
	char name[100];
	printf("请输入删除人的姓名:\n");
	scanf("%s",name);
	sprintf(sql, "delete from my_phone_book where name = '%s';",name);
	ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("delete record fail ! :%s\n",errmsg);
		exit(-1);
	}
}
