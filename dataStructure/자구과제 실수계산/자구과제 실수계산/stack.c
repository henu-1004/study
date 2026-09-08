#include"stack.h"

void push(node** top, char c) {
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

int SisEmpty(node** top) {
    if ((*top) == NULL) {
        return 1;
    }
    else
        return 0;
}

void freeSt(node** top) {
    while ((*top) != NULL) {
        node* cur = (*top);
        (*top) = cur->next;
        free(cur);
    }
    *top = NULL;
}