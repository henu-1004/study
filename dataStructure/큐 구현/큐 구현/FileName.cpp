#include<stdio.h>
#include<stdlib.h>

int A[6];
int front = -1;
int rear = -1;

int IsFull() {
	if (rear == 6) {
		return 1;
	}
	else
		return 0;
}

int isEmpty() {
	if (front == -1 && rear == -1) {
		return 1;
	}
	else
		return 0;
}

void Enque(int x) {
	if (IsFull()) {
		printf("list is full");
		return;
	}
	if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear++;
	}
		A[rear] = x;
}

void Deque() {
	if (isEmpty()) {
		return;
	}
	else if (front == rear) {
		front = rear = -1;
	}
	else
		front++;	
}


void print() {
	printf("ť �迭: ");
	for (int i = front; i <=rear; i++) {
		printf("%d", A[i]);
	}
	printf("\n");
}


int main() {
	Enque(1);
	Enque(2);
	Enque(3);
	Enque(4);
	print();
	Deque();
	Enque(5);
	print();
	Enque(6);
	Deque();
	Enque(7);
	print();
	Enque(8);

	return 0;
}