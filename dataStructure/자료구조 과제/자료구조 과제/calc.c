#include<stdio.h>
#include"stack.h"
#include"queue.h"

// 문자열 숫자로 바꾸는 함수하나있어야함
// 숫자면 큐, 연산자면 스택
// 숫자로 바꾼것들 계산하는 함수들 사칙연산 등
// 계산 한 값을 문자열에 집어넣는 함수?

/*for (int i = 0; i < strlen(infix); i++) {
    if (infix[i] >= '0' && infix[i] <= '9') {
        while (infix[idx] >= '0' && infix[idx] <= '9') {
            int num = 0;
            while (infix[idx] >= '0' && infix[idx] <= '9') {
                num = num * 10 + (infix[idx] - '0');
                idx++;
            }
            Enqueue(&(*front), num);
        }
    }*/


char* infixToPostfix(char infix[], char postfix[], que **front, node** top) {
    int idx = 0;
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            //Enqueue(&(*front), infix[i], 1);
            postfix[idx++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&(*top), infix[i]);
        }
        else if (infix[i] == ')') {
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
        else if (infix[i] == '*' || infix[i] == '/') {
            if (!SisEmpty(&(*top)) && ((*top)->data == '*' || (*top)->data == '/')) {
                postfix[idx++] = pop(&(*top));
            }
            push(&(*top), infix[i]);
        }
        else if (infix[i] == ' ') {
            continue;
        }
    }
    while (!SisEmpty(&(*top))) {
        postfix[idx++] = pop(&(*top));
    }
    return postfix;
}

//문자열 숫자로 변환
/*int changeStrToInt(char postfix[], que** front) {
    int num = 0;
    int idx = -1;
    char str[500] = { "" };
    while (1) {
        if (postfix[++idx] > 47 && postfix[idx] < 58) {
            str[idx++] = Dequeue(&(*front));
        }
      //  if (postfix[++idx] > 47 && postfix[idx] < 58) {
       //     num = num * 10 + (postfix[idx] - '0');
       // }
        //널이거나, 연산자면?
        else if (postfix[idx] == '\0' || (postfix[idx]<48 && postfix[idx]>57)) {
            break;
        }
    }
    return num;
}*/

void postfixEnque(char postfix[], node** top, que** front) {
    int idx;
    for (idx=0; idx < strlen(postfix); idx++) {
        if (postfix[idx] >= '0' && postfix[idx] <= '9') {
            int num = 0;
            while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                num = num * 10 + (postfix[idx] - '0');
                idx++;
            }
            Enqueue(&(*front), num, 1);
        }
        else if (postfix[idx] == '+' || postfix[idx] == '-' || postfix[idx] == '*' || postfix[idx] == '/' || postfix[idx] == '%') {
            Enqueue(&(*front), postfix[idx], 0);
        }
        else if (postfix[idx] == ' ') {
            continue;
        }
    }
}
        
int postfixCalc(que** front) {
    Qdata val;
    int result, sunseo=1;
    int n1[1] = { NULL }, n2[1] = { NULL };
    char op[1] = { NULL };
    while(QisEmpty!=1){
        val = Dequeue(&(*front));
        if (n1[0] != NULL && n2[0] != NULL && op[0] != NULL) {
            switch (op[0]) {
            case '+':
                result = n1[0] + n2[0];
                break;
            case '-':
                result = n1[0] - n2[0];
                break;
            case '*':
                result = n1[0] * n2[0];
                break;
            case '/':
                if (n2[0] == 0) {
                    printf("Error : div 0");
                    break;
                }
                result = n1[0] / n2[0];
                break;
            case '%':
                if (n2[0] == 0) {
                    printf("Error : div 0");
                    break;
                }
                result = n1[0] % n2[0];
                break;
            case '^':
                result = 1;
                for (int i = 0; i < n2[0]; i++) {
                    result *= n1[0];
                }
                break;
            }
            Enqueue(&(*front), result, 1);
        }
        if (n1[0] == NULL && val.type == 1) {
            n1[0] = val.data;
        }
        else if (op[0]==NULL && val.type == 0) {
            op[0] = val.data;
        }
        else if (n1[0] != NULL && n2[0] == NULL && val.type == 1) {
            n2[0] = val.data;
        }
        if (n2[0] == NULL && op[0] != NULL) {
            Enqueue(&(*front), op[0], 0);
        }
        if (n1[0] != NULL && n2[0] != NULL) {
            if (sunseo == 1) {
                Enqueue(&(*front), n1[0], 1);
                n1[0] = val.data;
                sunseo++;
            }
            if (sunseo == 2) {
                Enqueue(&(*front), n2[0], 1);
                n2[0] = val.data;
                sunseo--;
            }
        }
        
    }

}



/*int postfixCalc(char postfix[], node** top, que** front) {
    //만약 숫자, 숫자, 연산자면 계산
    //서순 안맞으면 큐 계속돌리기.
    else {
            int operand2 = Pop(&(*top));
            int operand1 = Pop(&(*top));
            int result;
            char operator = postfix[idx];
            switch (operator) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            case '^':
                result = 1;
                for (int i = 0; i < operand2; i++) {
                    result *= operand1;
                }
                break;
            }
            Push(&(*top), result);
            idx++;
        }
    return Pop(&(*top));
    int idx = 0;
    while (postfix[idx] != '\0') {
        if (postfix[idx] >= '0' && postfix[idx] <= '9') {
            int num = 0;
            while (postfix[idx] >= '0' && postfix[idx] <= '9') {
                num = num * 10 + (postfix[idx] - '0');
                idx++;
            }
            Push(&(*top), num);
        }
   // while (1) {
   //     if (postfix[++idx] > 47 && postfix[idx] < 58) {
   //         num = num * 10 + (postfix[idx] - '0');
   //     }
        //널이거나, 연산자면?
    //    else if (postfix[idx] == '\0' || (postfix[idx] < 48 && postfix[idx]>57)) {
     //       break;
     //   }
   // }
    int n1, n2;
    char op;
    int cnt = 0;
    n1 = (postfix[cnt++] - 0);
    n2 = (postfix[cnt++] - 0);
    op = (postfix[cnt++]);
    //op가 +면-면*면/면%면^면의 경우
    for (int i = 0; i < strlen(postfix); i++) {
        
    }

}*/