#ifndef QUEUE_H
#define QUEUE_H

#include<stdlib.h>

typedef struct QData {
    float data;
    int type;
}Qdata;

typedef struct Que {
    int type; //1이면 숫자, 0이면 연산자
    float data;
    struct Que* next;
}que;

que* getnewque(float data, int type);

void Enqueue(que** front, float data, int type);

int QisEmpty(que** front);

Qdata Dequeue(que** front);

void freeQue(que** front);


void printQue(que** front);
   


#endif // QUEUE_H