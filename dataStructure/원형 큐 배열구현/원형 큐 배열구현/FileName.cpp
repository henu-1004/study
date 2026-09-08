#include<stdio.h>
#include<string.h>

#define M 7
int A[M];
int front = 0;
int rear = 0;

int IsEmpty() {
    if (front == rear) {
        return 1;
    }
    else
        return 0;
}

void Enque(int x) {
    if ((rear + 1) % M == front) {
        return;
    }
    else if (IsEmpty()) {
        front = rear = 0;
    }
    rear = (rear + 1) % M;
    A[rear] = x;
}

void Deque() {
    if (IsEmpty()) {
        return;
    }
    else if (front == rear) {
        front = rear = 0;
    }
    front = (front + 1)%M;
}

int Front() {
    return A[front];
}

void print() {
    int i = front + 1;
    for (i; i != (rear+1)%M; i=(i+1)%M) {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main() {
    Enque(1);
    Enque(2);
    Enque(3);
    Enque(4);
    Enque(5);
    Enque(6);
    Deque();
    Enque(7);
    Deque();
    Enque(8);
    print();
    return 0;
}