#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* ptr;
}node;

node* head = NULL;

void insert() {
	node* tmp = (node*)malloc(sizeof(node));
	printf("숫자입력 : ");
	tmp->ptr = NULL;
	scanf_s("%d", &tmp->data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	node* cur = head;
	while (cur->ptr != NULL) {
		cur = cur->ptr;
	}
	cur->ptr = tmp;
}

void Reverse() {
	node* pre, * cur, * next;
	pre = NULL;
	cur = head;
	while (cur != NULL) {
		next = cur->ptr;
		cur->ptr = pre;
		pre = cur;
		cur = next;
	}
	head = pre;
}

void ptReverse() {
	node* pre, * cur, * next;
	pre = NULL;
	cur = head;
	while (cur != NULL) {
		next = cur->ptr;
		cur->ptr = pre;
		pre = cur;
		cur = next;
	}
	head = pre;
}

void print() {
	node* cur = head;
	while (cur != NULL) {
		printf("%d", cur->data);
		cur = cur->ptr;
		printf("\n");
	}
	printf("\n");
}


int main() {
	int n;
	printf("몇개의 데이터를 입력할것인가?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		insert();
	}
	printf("입력한 숫자들 \n");
	print();
	Reverse();
	print();
	ptReverse();
	print();
	return 0;
}


