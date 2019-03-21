#include<stdio.h>
int main()
{
	int sockfd;
	sockfd = InitNet();//初始化网络设置
	
	InitDataBase();//初始化数据库
	
	main_handler(sockfd);
		
	return 0;
}
