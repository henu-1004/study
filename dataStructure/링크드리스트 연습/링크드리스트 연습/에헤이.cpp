#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;

void insert() {
	node* tmp = (node*)malloc(sizeof(node));
	printf("수 입력 : ");
	scanf_s("%d", &tmp->data);
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		return;
	}
	tmp->next = head;
	head = tmp;
}

void print() {
	node* cur = (node*)malloc(sizeof(node));
	cur = head;
	while (cur != NULL) {
		printf("입력한 숫자 : %d", cur->data);
		cur = cur->next;
		printf("\n");
	}
}

int main() {
	int n;
	printf("몇개의 숫자를 입력?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		insert();
	}
	print();

	return 0;
}