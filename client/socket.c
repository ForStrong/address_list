#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include"../address.h"
//socket --connect --send --recv --close
int InitNet()
{
	struct sockaddr_in server_addr;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("sockfd");
		exit(1);
	
	}
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(3333);
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.111");
	int ret = connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));//server_addr服务器地址
	if(ret == -1)
	{
		perror("connect");	
		exit(1);
	}
	return sockfd;
}
//1.通知服务器，该客户端下线
//2.关闭TCP连接
//3.退出程序
void exit_client(int fd)
{
	Chat c;
	c.cmd = EXIT;
	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}

	close(fd);
	exit_show();
	exit(0);

}

void add_info(int fd)
{
	Chat c;
	printf("请输入姓名和电话:  \n");
	scanf("%s%s",c.name,c.tel);

	c.cmd = ADDINFO;	
	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
	printf("信息录入成功！\n");
}

void updata_info(int fd)
{
	Chat c;
	printf("请输入要修改联系人的姓名:  \n");
	scanf("%s",c.old_name);
	printf("请输入新的姓名和电话:  \n");
	scanf("%s%s",c.name,c.tel);

	c.cmd = UPDATEINFO;	
	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
	printf("信息修改成功！\n");
}

void delete_info(int fd)
{
	Chat c;
	memset(&c,0,sizeof(c));
	printf("请要修改人的姓名:  \n");
	scanf("%s",c.name);
	c.cmd = DELINFO;	
	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
	printf("信息删除成功！\n");
}

void search(int fd)
{
	Chat c;
	printf("请要查找人的姓名:  \n");
	scanf("%s",c.name);
	c.cmd = SEARCHINFO;	
	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
	while(1)//循环接收消息
	{
		memset(&c,0,sizeof(c));
		ret = recv(fd,&c,sizeof(c),0);
		if(-1 == ret)
		{
			perror("recv");
		}

		if(!strcmp(c.name,"bye") && !strcmp(c.tel,"bye"))
		{
			break;
		}

		printf("\t\t姓名%s          电话%s\n",c.name,c.tel);
	}
	sleep(3);	
}


void show_info(int fd)
{
	Chat c;
	
	c.cmd = SHOWINFO;

	int ret = send(fd,&c,sizeof(c),0);
	if(-1 == ret)
	{
		perror("send");
	}
	while(1)//循环接收消息
	{
		memset(&c,0,sizeof(c));
		ret = recv(fd,&c,sizeof(c),0);
		if(-1 == ret)
		{
			perror("recv");
		}

		if(!strcmp(c.name,"bye") && !strcmp(c.tel,"bye"))
		{
			break;
		}

		printf("\t\t姓名%s          电话%s\n",c.name,c.tel);
	}
	sleep(3);
}
