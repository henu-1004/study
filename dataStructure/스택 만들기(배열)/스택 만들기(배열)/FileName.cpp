#include<stdio.h>

#define maxsize 101
int top = -1;
int stack[maxsize];

void push(int x) {
	if (top == maxsize - 1) {
		printf("overflow");
		return;
	}
	stack[++top] = x;
}

void pop() {
	if (top == -1) {
		printf("error:값없음\n");
		return;
	}
	printf("pop실행\n");
	top-- ;
}

int Ptop() {
	return stack[top];
}

void IsEmpty() {
	if (top == -1) {
		printf("empty\n");
	}
	else
		printf("not empty\n");
}

void print() {
	printf("stack: ");
	for (int i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	push(7);
	push(2);
	push(3);
	push(4);
	print();
	pop();
	push(5);
	print();
	printf("top: %d\n", Ptop());
	pop();
	printf("top: %d\n", Ptop());
	pop();
	IsEmpty();
	pop();
	printf("top: %d\n", Ptop());
	pop();
	pop();
	IsEmpty();
	return 0;
}