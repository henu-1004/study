#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

que* getnewque(int data, int type) {
	que* newque = (que*)malloc(sizeof(que));
	newque->type = type;
	newque->data = data;
	newque->next = NULL;
	return newque;
}

void Enqueue(que** front, int data, int type) {
	que* tmp = getnewque(data, type);
	if (*front == NULL) {
		*front = tmp;
		return;
	}
	que* cur = *front;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	return;
}

Qdata Dequeue(que** front) {
	que* tmp = *front;
	Qdata val;
	int data = tmp->data;
	if(tmp->type==1){
		val.data = tmp->data;
		val.type = tmp->type;
	}
	else if (tmp->type == 0) {
		val.data=tmp->data;
		val.type = tmp->type;
	}
	*front = tmp->next;
	free(tmp);
	return val;
}
int QisEmpty(que** front) {
	if (*front == NULL) {
		return 1;
	}
	else
		return 0;
}

//프린트도 필요