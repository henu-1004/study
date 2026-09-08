#ifndef QUEUE_H
#define QUEUE_H
typedef struct QData {
	int data;
	int type;
}Qdata;

typedef struct Que{
	int type; //1이면 숫자, 0이면 연산자
	int data;
	struct Que* next;
	}que;
que* getnewnode(char data);
void Enqueue(que**front,int data, int type);
Qdata Dequeue(que**front);
int QisEmpty(que** front);

#endif