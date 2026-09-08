#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996);

typedef struct Stack {
    char data;
    struct Stack* link;
}stack;

void push(stack** top, char x) {
    stack* newnode = (stack*)malloc(sizeof(stack));
    newnode->link = *top;
    newnode->data = x;
    *top = newnode;
    return;
}

char Top(stack** top) {
    return (*top)->data;
}

char pop(stack** top) {
    stack* tmp = *top;
    char data = tmp->data;
    *top = tmp->link;
    free(tmp);
    return data;
}

int IsEmpty(stack** top) {
    if (*top == NULL) {
        return 1;
    }
    else
        return 0;
}

int check(stack** top, char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(top, str[i]);
        }
        else {
            if (IsEmpty(top)) {
                return 0;
            }
            char t = pop(top);
            if (t == '(' && str[i] == ')') {
                continue;
            }
            else if (t == '[' && str[i] == ']') {
                continue;
            }
            else if (t == '{' && str[i] == '}') {
                continue;
            }
            else {
                return 0;
            }
        }
    }
    if (IsEmpty(top)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    stack* top = NULL;
    char str[55] = { 0 };
    printf("°ýÈ£ ½Ö ÀÔ·Â\n>> ");
    scanf("%s", str);
    if (check(&top, str)) {
        printf("O\n");
    }
    else {
        printf("X\n");
    }
    return 0;
}