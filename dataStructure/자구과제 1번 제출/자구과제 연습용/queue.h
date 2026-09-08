#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int* array;
    int front, rear, size;
    unsigned cap;
} que;

que* createQueue(unsigned cap);
void Enqueue(que* queue, int item);
int Dequeue(que* queue);
int QisEmpty(que* queue);
int QisFull(que* queue);
void printQueue(que* queue);

#endif // QUEUE_H