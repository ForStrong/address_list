#include<stdio.h>
#include<sqlite3.h>
#include<stdlib.h>
#include"../address.h"

//1.创建数据库文件
//2.创建保存联系人信息的表
void InitDataBase()
{

	sqlite3 *ppdb;//数据库句柄
	
	int ret = sqlite3_open("address.db",&ppdb);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_open:%s\n",sqlite3_errmsg(ppdb));
		exit(1);
	}
	
	char sql[128] = {0};
	sprintf(sql,"create table if not exists address (name text, tel text);");
	ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_exec1:%s\n",sqlite3_errmsg(ppdb));
		exit(1);
	}
	sqlite3_close(ppdb);
}

void add_info(Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db",&ppdb);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n",sqlite3_errmsg(ppdb));
	}

	char sql[128] =  {0};
	sprintf(sql,"insert into address values ('%s','%s');",c->name,c->tel);
	ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}

void updata_info(Chat *c)
{
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db",&ppdb);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n",sqlite3_errmsg(ppdb));
	}

	char sql[128] =  {0};
	sprintf(sql,"update address set name = '%s',tel = '%s' where name = '%s';",c->name,c->tel,c->old_name);
	ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}

int sendinfo(void *para,int columnCount,char **columnVal,char **columnName)
{	
	int fd =*(int *)para;
	Chat c;

	strcpy(c.name,columnVal[0]);
	strcpy(c.tel,columnVal[1]);
	int ret = send(fd,&c,sizeof(c),0);
        if(-1 == ret)
        {
		perror("send");
        }
	
	return 0;


}

void search(int fd,Chat *c)
{
	sqlite3 *ppdb;
        int ret = sqlite3_open("address.db",&ppdb);
        if(ret != SQLITE_OK)
        {
                printf("sqlite3_open : %s\n",sqlite3_errmsg(ppdb));
        }

        char sql[128] =  {0};
	sprintf(sql,"select * from address where name = '%s';",c->name);
	ret = sqlite3_exec(ppdb,sql,sendinfo,&fd,NULL);
	if(ret != SQLITE_OK)
        {
                printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
        	exit(1);
	}
	Chat a;
	strcpy(a.name,"bye");
	strcpy(a.tel,"bye");
	ret = send(fd,&a,sizeof(a),0);
	if(-1 == ret)
	{
		perror("send");
	}
}

void show_info(int fd)
{
	sqlite3 *ppdb;
        int ret = sqlite3_open("address.db",&ppdb);
        if(ret != SQLITE_OK)
        {
                printf("sqlite3_open : %s\n",sqlite3_errmsg(ppdb));
        }

        char sql[128] = "select * from address;";
	
	ret = sqlite3_exec(ppdb,sql,sendinfo,&fd,NULL);
	if(ret != SQLITE_OK)
        {
                printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
        	exit(1);
	}

	Chat c;
	strcpy(c.name,"bye");
	strcpy(c.tel,"bye");
	ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
}

void delete_info(Chat *c){
	sqlite3 *ppdb;
	int ret = sqlite3_open("address.db",&ppdb);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_open : %s\n",sqlite3_errmsg(ppdb));
	}

	char sql[128] =  {0};
	sprintf(sql,"delete from address where name = '%s';",c->name);
	ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
	}
	sqlite3_close(ppdb);
}
