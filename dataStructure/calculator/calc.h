#ifndef _CALC_H
#define _CALC_H

#include "queue.h"
#include "stack.h"

int isOperator(char symbol);

int getOperatorPrecedence(char op);

que* infixToPostfix(char* exp);

int evaluatePostfix(que* exp);

#endif

