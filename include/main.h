#define num 20
struct node{
	char name[num];
	char sex[num];
	char birthday[num];
	char phone[num];
	char postcode[num];
	char addr[num];
	struct node * next;
};

typedef struct node Node;
typedef struct node * Link;

