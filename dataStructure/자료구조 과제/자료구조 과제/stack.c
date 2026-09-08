#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#pragma warning(disable:4996);

void push(node** top, char c){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = c;
    tmp->next = *top;
    *top = tmp;
    return;
}

char pop(node** top) {
    node* tmp = *top;
    char data = tmp->data;
    *top = tmp->next;
    free(tmp);
    return data;
}

int SisEmpty(node ** top) {
    if ((*top) == NULL) {
        return 1;
    }
    else
        return 0;
}

//프린트도 필요



