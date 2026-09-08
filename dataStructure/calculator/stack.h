#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;


Stack* createStack(unsigned cap);
int isStackEmpty(Stack* stack);
void push(Stack* stack, int c);
int pop(Stack* stack);
int peek(Stack* stack);
int SisEmpty(Stack* stack);
void freeStack(Stack* stack);
void printStack(Stack* stack);

#endif // STACK_H

