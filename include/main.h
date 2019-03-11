struct node{
	char name[8];
	char sex[4];
	char birthday[12];
	char phone[11];
	char postcode[7];
	char addr[30];
	struct node * next;
};

typedef struct node Node;
typedef struct node * Link;

