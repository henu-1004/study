#ifndef _CALC_H
#define _CALC_H

#include "queue.h"
#include "stack.h"

int isOperator(char Operator);

int OpPrio(char op);

que* infixToPostfix(char* exp);

int calcPostfix(que* exp);

#endif
