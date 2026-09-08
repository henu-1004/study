#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* top = NULL;

void push(int x) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = x;
	tmp->next = top;
	top = tmp;
}

void pop() {
	printf("pop실행\n");
	node* tmp=top;
	if (top == NULL) {
		printf("리스트 비었음");
		return;
	}
	top = tmp->next;
	free(tmp);
}

int Top() {
	return top->data;
}

void print() {
	node* cur = top;
	if (top == NULL) {
		printf("리스트가 비었음");
		return;
	}
	while (cur != NULL) {
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void IsEmpty() {
	if (top == NULL) {
		printf("empty\n");
	}
	else
		printf("not empty\n");
}

int main() {
	IsEmpty();
	push(9);
	push(8);
	printf("Top: %d\n", Top());
	push(7);
	print();
	pop();
	push(6);
	print();
	IsEmpty();
	pop();
	printf("Top: %d\n", Top());
	pop();
	print();
	pop();
	pop();
	IsEmpty();
	return 0;
}