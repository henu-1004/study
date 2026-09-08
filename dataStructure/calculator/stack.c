#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#pragma warning(disable:4996);

Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int c){
    if (!stack) {
        printf("Error: stack is NULL\n");
        exit(1);
    }
    if (stack->top == stack->capacity - 1) {
        printf("Error: stack is full, can't push\n");
        exit(1);
    }
    stack->array[++stack->top] = c;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Can't pop.\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

int SisEmpty(Stack* stack) {
    return (stack->top == -1) ? 1 : 0;
}

void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("%c ", stack->array[i]);
    printf("\n");
}

peek(Stack* stack) {
    return stack->array[stack->top];
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

