#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;

void Insert() {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	printf("입력 할 수: ");
	scanf_s("%d", &tmp->data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	return;
}

void print() {
	node* cur = head;
	printf("입력한 수:");
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	return;
}


void Reverse2(node* p) {
	if (p->next == NULL) {
		head = p;		
		return;
	}
	Reverse2(p->next);
	node* q = p->next;
	q->next = p;
	p->next = NULL;
	return;
}

void Reverse(node* cur) {
	if (cur->next == NULL) {
		head = cur;
		return;
	}
	Reverse(cur->next);
	node* p = cur->next;
	p->next = cur;
	cur->next = NULL;
}


int main() {
	int n;
	printf("몇 번 실행할 것인가?:");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		Insert();
	}
	print();
	printf("\n");
	Reverse(head);
	print();

	return 0;
}



