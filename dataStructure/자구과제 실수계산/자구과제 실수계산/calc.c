#include"calc.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void infixToPostfix(char infix[], char postfix[], que** front, node** top) {
    int idx = 0;
    int check = 0;
    int infixLength = strlen(infix);
    for (int i = 0; i < infixLength-1; i++) {
        if (!(infix[i] >= '0' && infix[i] <= '9') &&
            infix[i] != '+' && infix[i] != '-' &&
            infix[i] != '^' && infix[i] != '*' &&
            infix[i] != '/' && infix[i] != '%' &&
            infix[i] != '.') {
            printf("Error: Not a valid formula\n");
            return;
        }
        //printf("Valid formula\n");
    }
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