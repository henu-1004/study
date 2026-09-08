#ifndef CALC_H
#define CALC_H
#include"queue.h"
#include"stack.h"

void infixToPostfix(char infix[], char postfix[], que** front, node** top);

void postfixEnque(char postfix[], que** front);

int countFloat(float number);

float postfixCalc(que** front);

#endif 