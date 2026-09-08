#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '^';
}

int getOperatorPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

que* infixToPostfix(char* exp) {
    Stack* stack = createStack(strlen(exp));
    que* queue = createQueue(strlen(exp));

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            Enqueue(queue, num);
        }
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!SisEmpty(stack) && peek(stack) != '(')
                Enqueue(queue, pop(&stack));
            if (!SisEmpty(stack) && peek(stack) != '(')
                return NULL;
            else
                pop(stack);
        }
        else {
            while (!SisEmpty(stack) && getOperatorPrecedence(exp[i]) <= getOperatorPrecedence(peek(stack)) && peek(stack) != '(')
                Enqueue(queue, pop(stack));
            push(stack, exp[i]);
        }
    }

    while (!SisEmpty(stack))
        Enqueue(queue, pop(stack));

    return queue;
}

int evaluatePostfix(que* exp) {
    Stack* st = createStack(exp->cap);
    while (!QisEmpty(exp)) {
        int symbol = Dequeue(exp);
        if (!isOperator(symbol)) {
            push(st, symbol); 

        } else {
            int right = pop(st);
            int left = pop(st);
            if (symbol == '+')
                push(st, left + right); 
            else if (symbol == '-')
                push(st, left - right);
            else if (symbol == '*')
                push(st, left * right);
            else if (symbol == '/') {
                if(right == 0){
                    printf("Divide by zero\n");
                    exit(-1);
                }
                push(st, left / right);
            }
            else if (symbol == '%') {
                if(right == 0){
                    printf("Modulo by zero\n");
                    exit(-1);
                }
                push(st, left % right);
            }
            else if (symbol == '^') {
                int result = 1;
                for (int i = 0; i < right; i++) {
                    result *= left;
                }
                push(st, result);
            }
        }
    }

    int result = pop(st);
    freeStack(st);
    return result;
}
