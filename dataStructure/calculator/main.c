#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"calc.h"
#include "queue.h"

int main() {
   char Infix[5000];

   printf("문자열 입력(엔터만 입력시 종료): ");
   fgets(Infix, sizeof(Infix), stdin);
   while (1) {
      // \n 만 있는 경우 - 즉, 사용자가 엔터만 누른 경우
      if (strlen(Infix) == 2 || strcmp(Infix, "\n")==0) {
         printf("프로그램 종료\n");
         break;
      }
      else {
         printf("계산함\n");
        Infix[strcspn(Infix, "\n")] = 0; // 줄바꿈 문자 제거

         // 중위표기법을 후위표기법으로 변환
         que* Postfix = infixToPostfix(Infix);
         if (Postfix == NULL) {
            printf("잘못된 수식입니다.\n");
         } else {
            // 후위표기법 수식을 계산
            int result = evaluatePostfix(Postfix);
            printf("%d", result);
            printf("결과: %c\n", result);
            free(Postfix); // Queue 메모리 해제
         }

         printf("문자열 입력(엔터만 입력시 종료): ");
         fgets(Infix, sizeof(Infix), stdin);
      }
   }
   return 0;
}

