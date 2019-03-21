#include<stdio.h>
#include<sys/types.h>          /* See NOTES */
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<pthread.h>
#include"../address.h"

int fd[1024] = {0};
pthread_t tid ;//线程号--线程标识符
//socket -- bind -- listen --accept --recv --send --close
int InitNet()
{
        struct sockaddr_in server_addr;//地址结构
        int sockfd = socket(AF_INET,SOCK_STREAM,0);//套接字描述符: ipv4 流式
        if(-1 == sockfd)
        {
                 perror("socket");
                exit(1);


        }
	
	int opt = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = PF_INET;//设置地址族 ipv4
	server_addr.sin_port = htons(3333);//设置端口号
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.111");//ip地址
	int ret = bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
	if(ret == -1)
        {
                 perror("bind");
                exit(1);
        }

        ret = listen(sockfd,10);//最大请求数
	if(ret == -1)
        {
                 perror("listen");
                exit(1);
        }

	return sockfd;

}

void exit_client(int fd)
{
	printf("客户端 %d 下线\n",fd);
	close(fd);//关闭TCP连接
	pthread_exit((void *)0);//线程退出
}
	
void *client_handler(void *arg)//线程函数
{
	Chat c;
	int fd = *(int *)arg;
	while(1)
	{
		int ret = recv(fd,&c,sizeof(c),0);
		if(-1 == ret)
		{
			perror("recv");
		}
		switch(c.cmd)
		{
			case ADDINFO:
				add_info(&c);
				break;
			case DELINFO:
				delete_info(&c);
                                break;
			case UPDATEINFO:
				updata_info(&c);
                                break;
			case SEARCHINFO:
				search(fd,&c);
                                break;
			case SHOWINFO:
				show_info(fd);
                                break;
			case EXIT:
				exit_client(fd);
                                break;
			
		}
	}
}

void main_handler(int sockfd)
{
	int i =0;
	struct sockaddr_in client_addr;
	int length = sizeof(client_addr);
	while(1)
	{
		for(i =0 ; i<1024;i++)
		{
			if(0 == fd[i])
			{
				break;
			}
		}
		fd[i] = accept(sockfd,(struct sockaddr *)&client_addr,&length);//接收客户端的连接，client_addr客户端地址
		printf("接收客户端连接%d\n",fd[i]);
		int ret = pthread_create(&tid,NULL,client_handler,&fd[i]);//启动线程处理连接（一个线程对应一个客户端）--client_handler线程函数的起始地址--fd[i]函数的参数
		if(-1 == ret)
		{
			perror("pthread_create");
			exit(1);
		}
	}
}
