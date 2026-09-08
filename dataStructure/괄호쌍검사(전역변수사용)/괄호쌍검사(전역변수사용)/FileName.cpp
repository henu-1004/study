#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char data;
    struct Stack* link;
} stack;

stack* top = NULL;

void push(char x) {
    stack* tmp = (stack*)malloc(sizeof(stack));
    tmp->link = top;
    tmp->data = x;
    top = tmp;
}

char pop() {
    if (top == NULL) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    stack* cur = top;
    char x = cur->data;
    top = cur->link;
    free(cur);
    return x;
}

int is_empty() {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int check(char* x) {
    int len = strlen(x);
    for (int i = 0; i < len; i++) {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
            push(x[i]);
        }
        else if (x[i] == ')' || x[i] == '}' || x[i] == ']') {
            if (is_empty()) {
                return 0;
            }
            char p = pop();
            if ((p == '(' && x[i] != ')') || (p == '{' && x[i] != '}') || (p == '[' && x[i] != ']')) {
                return 0;
            }
        }
    }
    if (is_empty()) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char str[30] = {NULL};
    printf("괄호 쌍 입력: ");
    scanf_s("%s", str,sizeof(str));

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != '(' && str[i] != ')' && str[i] != '{' && str[i] != '}'
            && str[i] != '[' && str[i] != ']') {
            printf("괄호이외의 문자가 포함됨.\n");
            return 0;
        }
    }

    if (check(str)) {
        printf("올바른 괄호 쌍입니다.\n");
    }
    else {
        printf("올바르지 않은 괄호 쌍입니다.\n");
    }

    return 0;
}