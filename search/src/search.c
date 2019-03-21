#include<stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
int displaycb(void * para, int ncolumn, char * column_value[],char ** column_name)
{
	int i;
	for(i = 0; i < ncolumn; i++)
	{
		printf("%s\t",column_value[i]);
	}
	printf("\n");
	
	return 0;
}

void inquire_usecb(sqlite3 * db)
{
	int ret;
	char * errmsg;
	char *sql;

	sql = "select * from my_phone_book;";
	printf("id\tname\tphone\t\n");
	ret = sqlite3_exec(db,sql,displaycb,NULL,&errmsg);

	if(ret != SQLITE_OK)
	{
		printf("select fail ! :%s\n",errmsg);
		exit(-1);
	}
}

void search_record(sqlite3 * db)
{
	int ret;
	char * errmsg;
	char sql[100];
	char name[100];
	printf("输入查找人的姓名 \n");
	scanf("%s",name);
	printf("id\tname\tphone\t\n");
	sprintf(sql,"select * from my_phone_book where name='%s';",name);
	ret = sqlite3_exec(db,sql,displaycb,NULL,&errmsg);
	if(ret!=SQLITE_OK)
	{
		printf("select fail!:%s\n",errmsg);
		exit(-1);
	}
}
