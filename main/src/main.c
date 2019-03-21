#include<stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
void safe_flush(FILE *fp)
{

	int ch;
	while( (ch = fgetc(fp)) != EOF && ch != '\n' );          
}

void create_table(sqlite3 * db)
{
	int ret;
	char * errmsg;
	char * sql;

	sql = "create table if not exists my_phone_book (id integer primary key,name text,phone text);";

	ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);

	if(ret != SQLITE_OK)
	{
		printf("creat_table fail ! :%s\n",errmsg);
		exit(-1);
	}
}

int main()
{
	
	sqlite3 * db = NULL;
	int ret;
	int flag;
	ret = sqlite3_open("phone_book.db",&db);
	if(ret != SQLITE_OK)
	{
		printf("open database error: %s\n",sqlite3_errmsg(db));
		exit(-1);
	}
	create_table(db);
	while(1){
		showMenu();
loop:printf("请输入代号(1~6): ");
	 scanf("%d",&flag);
	 if(flag < 1 || flag > 6){
		 printf("输入格式有误，请重新输入！\n");
		 safe_flush(stdin);
		 goto loop;
	 }
	 switch(flag){
		 case 1:insert_record(db);break;//添加
		 case 2:search_record(db);break;//查找
		 case 3:inquire_usecb(db);break;//显示
		 case 4:update_record(db);break;//更新
		 case 5:delete_record(db);break;//删除
		 case 6:exit_show();exit(0);break;//退出
	 }
	}
 	
	return 0;
}
