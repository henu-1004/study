#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;


void delTail() {
	node* del = head;
	node* pre = NULL;
	while (del->next != NULL) {
		pre = del;
		del = del->next;
	}
	if (pre != NULL) {
		pre->next = NULL;
	}
	else
		head = NULL;
	free(del);
}

void insert() {
	node* tmp = (node *)malloc(sizeof(node));
	printf("숫자입력 : ");
	tmp->next = NULL;
	scanf_s("%d", &tmp->data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	node* cur = head;
	while (cur->next!= NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
}

void print() {
	node* cur = head;
	while (cur != NULL) {
		printf("%d", cur->data);
		cur = cur->next;
		printf("\n");
	}
	printf("\n");
}

void printA(node* curNode) {
	printf("%d", curNode->data);
	if (curNode->next != NULL) {
		curNode = curNode->ptr;
		printA(curnode);
	}
}


void Rvprint(node* curNode) {
	if (curNode->next != NULL) {
		curNode = curNode->ptr;
		Rvprint(curNode);
	}
	printf("%d", curNode->data);
}



int main() {
	int n;
	printf("몇개의 데이터를 입력할것인가?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		insert();
	}
	printf("입력한 숫자들 \n");
	printA(head);
	Rvprint(head);

	delTail();
	printA(head);

	return 0;
}


