#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* insert(node* head) {
    node* tmp = (node*)malloc(sizeof(node));
    printf("숫자입력 : ");
    scanf_s("%d", &tmp->data);
    tmp->next = NULL;
    if (head == NULL) {
        head = tmp;
        return head;
    }
    tmp->next = head;
    head = tmp;
    return head;
}

void print(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;  // 지역변수로 선언된 head
    int n;
    printf("몇 개의 숫자를 입력하시겠습니까? ");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        head = insert(head);
    }
    printf("입력한 숫자들: ");
    print(head);
    return 0;
}