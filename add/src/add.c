#include<stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void insert_record(sqlite3 * db)
{
	int ret;
	char * errmsg;
	char sql[100];

	char name[100];
	char phone[100];
	printf("输入姓名:\n");
	scanf("%s",name);
	printf("输入电话:\n");
	scanf("%s",phone);

	sprintf(sql, "insert into my_phone_book (name,phone) values('%s','%s');",name,phone);

	ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);

	if(ret != SQLITE_OK)
	{
		printf("insert record fail ! :%s\n",errmsg);
		exit(-1);
	}
}
