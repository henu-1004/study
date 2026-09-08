#ifndef STACK_H
#define STACK_H

#include<stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
}node;

void push(node** top, char c);

char pop(node** top);

int SisEmpty(node** top);

void freeSt(node** top);


#endif 