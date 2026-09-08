#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* ptr;
}node;

node* head = NULL;


void Insert(int data, int n) {
	int i, listsize=0;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->ptr = NULL;
	node* cur = head;
	while (cur != NULL) {
		listsize++;
		cur = cur->ptr;
	}
	if (n > listsize + 1) {
		printf("아직 생성되지 않은 크기의 리스트위치를 선택함.");
		return;
	}
	if (n == 1) {
		tmp->ptr = head;
		head = tmp;
		return;
	}
	cur = head;
	for (i = 1; i < n-1; i++) {
		cur = cur->ptr;
	}
	tmp->ptr = cur->ptr;
	cur->ptr = tmp;
	return;
}

void insertAtIndex(int data, int n) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->ptr = NULL;
	if (n == 1) {
		tmp->ptr = head;
		head = tmp;
		return;
	}
	node* cur = head;
	for (int i = 0; i < n - 2; i++) {
		cur = cur->ptr;
	}
	tmp->ptr = cur->ptr;
	cur->ptr = tmp;
	return;
}

void print() {
	node* cur = head;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->ptr;
		
	}
	return;
}

int main() {
	Insert(3, 1);
	Insert(2, 2);
	Insert(5, 1);
	insertAtIndex(8, 3);
	print();
	Insert(8, 3);
	Insert(77, 8);
	Insert(4, 1);
	print();
	return 0;
}