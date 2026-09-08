#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

que* createQueue(unsigned cap) {
    que* queue = (que*)malloc(sizeof(que));
    queue->cap = cap;
    queue->front = queue->size = 0;
    queue->rear = cap - 1;
    queue->array = (char*)malloc(queue->cap * sizeof(char));
    return queue;
}

void Enqueue(que* queue, int item) {
    if (QisFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int Dequeue(que* queue) {
    if (QisEmpty(queue))
        return;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size = queue->size - 1;
    return item;
}

char front(que* queue) {
    return queue->array[queue->front];
}

char rear(que* queue) {
    return queue->array[queue->rear];
}

int QisEmpty(que* queue) {
    return (queue->size == 0);
}
int QisFull(que* queue) {
    return (queue->size == queue->cap);
}

void printQueue(que* queue) {
    int count = queue->size;
    int start = queue->front;
    while (count--) {
        printf("%d ", queue->array[start]);
        start = (start + 1) % queue->cap;
    }
    printf("\n");
}
