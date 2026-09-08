#include<stdio.h>

#define Max_size 99
int A[Max_size];
int top = -1;

void push(int x) {
	top++;
	if (top == Max_size - 1) {
		printf("overflow");
		return;
	}
	A[top] = x;
}

int Top() {
	return A[top];
}

void pop() {
	printf("pop실행\n");
	if (top == -1) {
		printf("리스트가 비었음\n");
		return;
	}
	top--;
}

void IsEmpty() {
	if (top == -1) {
		printf("empty\n");
	}
	else
		printf("not empty\n");
}

void print() {
	printf("Stack: ");
	for (int i = 0; i <= top; i++) {
		printf("%d ", A[i]);
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
	push(9);
	push(8);
	print();
	pop();
	pop();
	print();
	pop();
	pop();
	IsEmpty();


	return 0;
}