#ifndef STACK_H
#define STACK_H

typedef struct Node {
    char data;
    struct Node * next;
}node;

int check(node** top, char* str);
int SIsEmpty(node** top);
void push(node** top, char c);
char pop(node** top);

#endif