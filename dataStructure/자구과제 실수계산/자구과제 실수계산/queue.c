#include"queue.h"

que* getnewque(float data, int type) {
    que* newque = (que*)malloc(sizeof(que));
    newque->type = type;
    newque->data = data;
    newque->next = NULL;
    return newque;
}

void Enqueue(que** front, float data, int type) {
    que* tmp = getnewque(data, type);
    if (*front == NULL) {
        *front = tmp;
        return;
    }
    que* cur = *front;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return;
}

int QisEmpty(que** front) {
    if ((*front) == NULL) {
        return 1;
    }
    else
        return 0;
}

Qdata Dequeue(que** front) {
    while (QisEmpty(&(*front)) != 1) {
        que* tmp = *front;
        Qdata val = { -1,-1 };
        int data = tmp->data;
        if (tmp->type == 1) {
            val.data = tmp->data;
            val.type = tmp->type;
        }
        else { //if (tmp->type == 0) 
            val.data = tmp->data;
            val.type = tmp->type;
        }
        *front = tmp->next;
        free(tmp);
        return val;

    }

}

void freeQue(que** front) {
    // printf("\n free all que ½ÇÇà");
    que* cur = *front;
    while (cur != NULL) {
        que* next = cur->next;
        free(cur);
        cur = next;
    }
    *front = NULL;
}


void printQue(que** front) {
    que* cur = *front;
    // if (QisEmpty(*(&front) == 1)) {
    //    printf("QisEmpty");
    //     return;
    // }
    printf("Qprint: ");
    while (cur != NULL) {
        if (cur->type == 1) {
            printf("%f", cur->data);
        }
        else
            printf("%c", cur->data);
        cur = cur->next;
    }
}
