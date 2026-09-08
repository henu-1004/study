#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct QData {
    float data;
    int type;
}Qdata;

typedef struct Que {
    int type; //1이면 숫자, 0이면 연산자
    float data;
    struct Que* next;
}que;

typedef struct Node {
    char data;
    struct Node* next;
}node;

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
    // printf("\n free all que 실행");
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

//프린트도 필요

void infixToPostfix(char infix[], char postfix[], que** front, node** top) {
    int idx = 0;
    int check = 0;
    //int dotF = 0;  // 소수점 여부

    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[idx++] = infix[i];
        }
        else if (infix[i] == '.') {
            //dotF = 1;
            postfix[idx++] = infix[i];
        }
        else if (infix[i] < '0' || infix[i] > '9') {
            postfix[idx++] = ',';
        }
        if (infix[i] == '(') {
            push(&(*top), infix[i]);
            check++;
        }
        else if (infix[i] == ')') {
            check--;
            while ((*top)->data != '(') {
                postfix[idx++] = pop(&(*top));
            }
            pop(&(*top));
        }
        else if (infix[i] == '+' || infix[i] == '-') {
            while (!SisEmpty(&(*top)) && (*top)->data != '(') {
                postfix[idx++] = pop(&(*top));
            }
            push(&(*top), infix[i]);
        }
        else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%') {
            while (!SisEmpty(&(*top)) && ((*top)->data == '*' || (*top)->data == '/' || (*top)->data == '%' || (*top)->data == '^')) {
                postfix[idx++] = pop(&(*top));
            }
            push(&(*top), infix[i]);
        }
        else if (infix[i] == '^') {
            while (!SisEmpty(&(*top)) && ((*top)->data == '^')) {
                postfix[idx++] = pop(&(*top));
            }
            push(&(*top), infix[i]);
        }
        //else //if (infix[i] == ' ') {
           // continue;
        //}
    }
    while (!SisEmpty(&(*top))) {
        postfix[idx++] = pop(&(*top));
    }
    if (check != 0) {
        postfix = '\0';
    }
    freeSt(&(*top));
    return;
}
//인큐 실패코드
/*void postfixEnque(char postfix[], que** front) {
    int idx;
    for (idx = 0; idx < strlen(postfix); idx++) {

        if (postfix[idx] >= '0' && postfix[idx] <= '9' || postfix[idx] == '.') {
            float num = 0;
            float Fnum = 0;
            while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                num = num * 10 + (postfix[idx] - '0');
                idx++;
            }
            printf("just num: %f", num);
            if (postfix[idx] == '.') {
                int cnt = 0;
                int j = 1;
                while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                    Fnum = Fnum * 10 + (postfix[idx] - '0');
                    printf("F num: %f", Fnum);
                    idx++;
                    cnt++;
                }
                for (int i = 1; i <= cnt; i++) {
                    j = j * 10;
                }
                Fnum = Fnum / j;
                printf("F num: %f", Fnum);
            }
            num = num + Fnum;
            Enqueue(&(*front), num, 1);
        }

        if (postfix[idx] == '+' || postfix[idx] == '-' || postfix[idx] == '*' || postfix[idx] == '/' || postfix[idx] == '%' || postfix[idx] == '^') {
            Enqueue(&(*front), postfix[idx], 0);

        }
        else //if (postfix[idx] == ' ') {
            continue;
        //}
    }
}*/


void postfixEnque(char postfix[], que** front) {
    int idx = 0;
    while (idx < strlen(postfix)) {
        if (postfix[idx] >= '0' && postfix[idx] <= '9' || postfix[idx] == '.') {
            float num = 0;
            float Fnum = 0;
            while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                num = num * 10 + (postfix[idx] - '0');
                idx++;
            }
            // printf("just num: %f\n", num);

            if (postfix[idx] == '.') {
                int cnt = 0;
                int j = 1;
                idx++;
                while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                    Fnum = Fnum * 10 + (postfix[idx] - '0');
                    //printf("F num: %f\n", Fnum);
                    idx++;
                    cnt++;
                }
                for (int i = 1; i <= cnt; i++) {
                    j = j * 10;
                }
                Fnum = Fnum / j;
                // printf("F num: %f\n", Fnum);
            }
            num = num + Fnum;
            Enqueue(&(*front), num, 1);
        }

        if (postfix[idx] == '+' || postfix[idx] == '-' || postfix[idx] == '*' || postfix[idx] == '/' || postfix[idx] == '%' || postfix[idx] == '^') {
            Enqueue(&(*front), postfix[idx], 0);
        }

        idx++;
    }
}

int countFloat(float number) {
    int cnt = 0;
    float Fnum = number - (int)number;

    while (Fnum != roundf(Fnum)) {
        cnt++;
        Fnum *= 10;
        Fnum -= (int)Fnum;
    }

    return cnt;
}

float postfixCalc(que** front) {
    Qdata val;
    float result = 0;
    int sunseo = 1;
    float n1 = 0, n2 = 0;
    int isn1 = 0;
    int isn2 = 0;
    char op = '\0';
    while (1) {
        val = Dequeue(&(*front));
        if (isn1 == 1 && isn2 == 1 && op != '\0') {
            //printf("\n계산시작");
            switch (op) {
            case '+':
                result = n1 + n2;
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            case '-':
                result = n1 - n2;
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            case '*':
                result = n1 * n2;
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            case '/':
                if (n2 == 0) {
                    printf("Error : div 0");
                    break;
                }
                result = n1 / n2;
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            case '%':
                if (n2 == 0) {
                    printf("Error : div 0");
                    break;
                }
                int bigger = 0;
                int n1F = countFloat(n1);
                int n2F = countFloat(n2);
                if (n1F > n2F) { bigger = n1F; }
                else {
                    bigger = n2F;
                }
                n1 = (n1 * n1F);
                n2 = (n2 * n2F);
                result = (int)n1 % (int)n2;
                for (int i = 0; i < bigger; i++) {
                    result = result / 10;
                }
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            case '^':
                result = 1;
                for (int i = 0; i < n2; i++) {
                    result *= n1;
                }
                isn1 = 0, isn2 = 0;
                op = '\0';
                break;
            }
            Enqueue(&(*front), result, 1);
            //printf("\n !!%d", result);
            //val = Dequeue(&(*front));
            if ((*front)->next == NULL) break;
        }
        if (isn1 == 0 && val.type == 1) {
            n1 = val.data;
            isn1 = 1;
            //  printf("\nn1:%f", n1);
        }
        else if (op == '\0' && val.type == 0) {
            op = val.data;
            //  printf("\nop:%c", op);
            if (isn2 == 0 && op != '\0') {
                Enqueue(&(*front), op, 0);
                op = '\0';
            }
        }
        else if (isn1 == 1 && isn2 == 0 && val.type == 1) {
            n2 = val.data;
            isn2 = 1;
            // printf("\nn2:%f", n2);
        }
        else if (isn2 == 0 && op != '\0') {
            if (isn1 == 1) {
                Enqueue(&(*front), n1, 1);
                isn1 = 0;
                n1 = 0;
            }
            Enqueue(&(*front), op, 0);
            op = '\0';

        }
        else if (isn1 == 1 && isn2 == 1) {
            if (sunseo == 1) {
                Enqueue(&(*front), n1, 1);
                n1 = val.data;
                // printf("\n둘다 참,n1:%d", n1);
                sunseo++;
            }
            else if (sunseo == 2) {
                Enqueue(&(*front), n2, 1);
                n2 = val.data;
                // printf("\n둘다 참, n2:%d", n2);
                sunseo--;
            }
        }
        //val = Dequeue(&(*front));

    }
    val = Dequeue(&(*front));
    freeQue(&(*front));
    return val.data;
}

int main() {
    char Infix[5000] = { "" };
    que* front = NULL;
    node* top = NULL;
    while (1) {
        char Postfix[5000] = { "" };
        printf("숫자 입력(엔터만 입력시 종료)");
        fgets(Infix, sizeof(Infix), stdin);
        if (strlen(Infix) == 1 && Infix[0] == '\n') {
            printf("프로그램 종료");
            break;
        }

        else {
            printf("계산함");
            infixToPostfix(Infix, Postfix, &front, &top);
            if (Postfix == '\0') {
                printf("괄호쌍오류");
            }
            else {
                // strcpy(str, Postfix);
                printf("postfix: %s \n", Postfix);
                postfixEnque(Postfix, &front);
                printQue(&front);
                printf("\n");
                float result = postfixCalc(&front);
                printf("result: %.2f\n", result);

            }
            //fgets(Infix, sizeof(Infix), stdin);
        }

    }
    return 0;
}







