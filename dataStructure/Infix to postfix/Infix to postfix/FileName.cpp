#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	char data;
	struct Stack* link;
}stack;

stack* top = NULL;

void push(char A) {
	stack* tmp = (stack*)malloc(sizeof(stack));
	tmp->data = A;
	tmp->link = top;
	top = tmp;
	return;
}

char pop() {
	stack* tmp = top;
	char data = tmp->data;
	top = tmp->link;
	free(tmp);
	return data;
}

int isEmpty() {
	if (top == NULL) {
		return 1;
	}
	else
		return 0;
}

char Top() {
	return top->data;
}

char* infixToPostfix(char infix[], char postfix[]) {
	int cnt = 0;
	for (int i = 0; i < strlen(infix); i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[cnt++]=infix[i];
		}
		else if (infix[i] == '(') {
			push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (top->data != '(') {
				postfix[cnt++] = pop();
			}
			pop();
		}
		else if (infix[i] == '+' || infix[i] == '-') {
			while (!isEmpty() && top->data != '(') {
				postfix[cnt++] = pop();		
			}
			push(infix[i]);
		}
		else if (infix[i] == '*' || infix[i] == '/') {
			if(!isEmpty() && (top->data == '*' || top->data == '/')) {
				postfix[cnt++] = pop();
			}
			push(infix[i]);
			
		}
	}
	while (!isEmpty()) {
		postfix[cnt++] = pop();
	}
	return postfix;
}

int main() {
	char infix[101];
	char postfix[101] = { NULL };
	scanf_s("%s", infix, sizeof(infix));
	infixToPostfix(infix, postfix);
	printf("postfix: ");
	for (int i = 0; postfix[i] != NULL; i++) {
		printf("%c", postfix[i]);
	}
	
	return 0;
}