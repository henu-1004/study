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
	if (top == NULL) {
		printf("리스트가 비었음\n");
		return;
	}
	node* cur=top;
	top = cur->next;
	free(cur);
}

int Top() {
	return top->data;
}

void IsEmpty() {
	if (top == NULL) {
		printf("empty\n");
	}
	else
		printf("not empty\n");
}

void print() {
	node* cur = top;
	printf("Stack: ");
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main() {
	IsEmpty();
	push(5);
	push(6);
	print();
	printf("Top: %d\n", Top());
	pop();
	push(8);
	push(9);
	IsEmpty();
	print();
	pop();
	printf("Top: %d\n", Top());
	pop();
	pop();
	pop();
	IsEmpty();

	return 0;
}