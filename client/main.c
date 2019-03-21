#include<stdio.h>
int main()
{	
	int sockfd;
	sockfd = InitNet();//初始化网络
	main_handler(sockfd);
	return 0;
}
