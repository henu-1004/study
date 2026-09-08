#include <stdio.h>
#include <stdlib.h>

// 단순 연결리스트의 노드 구조체
typedef struct node {
    int data;
    struct node* next;
} Node;

// 단순 연결리스트의 헤드 포인터 전달 방식에 따른 삽입 함수
void insertNode(Node** phead, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 동적 할당
    newNode->data = data;
    newNode->next = NULL;
    if (*phead == NULL) { // 리스트가 비어있을 경우
        *phead = newNode;
    }
    else { // 리스트가 비어있지 않을 경우
        newNode->next = *phead;
        *phead = newNode;
    }
}

int main() {
    Node* head = NULL; // 헤드 포인터 초기화
    int data;

    // 키보드에서 입력받은 값을 리스트에 삽입
    while (1) {
        printf("Enter a number (0 to quit): ");
        scanf_s("%d", &data);
        if (data == 0) break;
        insertNode(&head, data);
    }

    // 리스트 출력
    Node* cur = head;
    printf("List: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}