#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"calc.h"


int main() {
    char Infix[5000] = { "" };
    que* front = NULL;
    node* top = NULL;
    while (1) {
        char Postfix[5000] = { "" };
        printf(">>>");
        fgets(Infix, sizeof(Infix), stdin);
        if (strlen(Infix) == 1 && Infix[0] == '\n') {
            printf("finish");
            break;
        }

        else {
           // printf("계산함");
            infixToPostfix(Infix, Postfix, &front, &top);
            if (Postfix == '\0') {
                printf("error");//괄호쌍
            }
            else {
                // strcpy(str, Postfix);
               // printf("postfix: %s \n", Postfix);
                postfixEnque(Postfix, &front);
                //printQue(&front);
                printf("\n");
                float result = postfixCalc(&front);
                printf("result: %.2f\n", result);

            }
            //fgets(Infix, sizeof(Infix), stdin);
        }

    }
    return 0;
}







