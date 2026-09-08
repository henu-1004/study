#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;

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
	printf("%d\n", curNode->data);
	if (curNode->next != NULL) {
		curNode = curNode->next;
		printA(curNode);
	}
}

void Rvprint(node* curNode) {
	if (curNode->next == NULL) {
		printf("%d\n", curNode->data);
		return;
	}
	//node* ptr = curNode;
	Rvprint(curNode->next);
	printf("%d\n", curNode->data);
}


//잘못된 리버스>>커런트는 Rv(3)일때도 3, Rv(2)일때도 3임. >> 3이 두번출력, Rv(1)이면 cur=2라서 2출력
/*void Rvprint(node* curNode) {
	if (curNode->next != NULL) {
		curNode = curNode->ptr;
		Rvprint(curnode);
	}
	printf("%d", curNode->data);
}
*/

int main() {
	int n;
	printf("몇개의 데이터를 입력할것인가?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		insert();
	}
	printf("입력한 숫자들 \n");
	printA(head);
	printf("\n");
	Rvprint(head);


	return 0;
}


