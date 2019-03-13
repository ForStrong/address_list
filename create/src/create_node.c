#include"../../include/main.h"
#include<stdio.h>
#include<stdlib.h>
void create_node(Link * new_node){
	*new_node = (Link)malloc(sizeof(Node));
	is_malloc_ok(*new_node);
}

