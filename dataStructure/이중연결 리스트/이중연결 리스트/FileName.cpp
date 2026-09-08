#include<stdio.h>
#include<stdlib.h>

typedef struct DNode {
	int data;
	struct DNode* next;
	struct DNode* pre;
}node;

node* head = NULL;

node* getN() {
	node* newnode = (node*)malloc(sizeof(node));
	printf("입력할 숫자: ");
	scanf_s("%d", &newnode->data);
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}

void InsertAtHead() {
	node* tmp = getN();
	if (head == NULL) {
		head = tmp;
		return;
	}
	tmp->next = head;
	head->pre = tmp;
	head = tmp;
	return;
}

void delHead() {
	// 빈 리스트인 경우
	if (head == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	node* del = head;
	head = head->next;
	if (head != NULL) {
		head->pre = NULL;
	}
	free(del);
	return;
}

void delWant(int pos) {
	// 빈 리스트인 경우
	if (head == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}
	// 삭제할 위치가 1인 경우
	if (pos == 1) {
		node* del = head;
		head = head->next;
		if (head != NULL) {
			head->pre = NULL;
		}
		free(del);
		return;
	}
	// 삭제할 위치가 1보다 큰 경우
	node* cur = head;
	for (int i = 1; i < pos; i++) {
		if (cur == NULL) {
			printf("삭제할 위치가 리스트의 크기를 벗어났습니다.\n");
			return;
		}
		cur = cur->next;
	}
	cur->pre->next = cur->next;
	if (cur->next != NULL) {
		cur->next->pre = cur->pre;
	}
	free(cur);
	return;
}

	void InsertAtTail() {
		node* tmp = getN();
		if (head == NULL) {
			head = tmp;
			return;
		}
		node* cur=head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->pre = cur;
	}

void print() {
	printf("정방향 출력");
	node* cur=head;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	return;
}

void Revprint() {
	printf("역방향 출력");
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	while (cur->pre != NULL) {
		printf("%d ", cur->data);
		cur = cur->pre;
	}
	printf("%d", cur->data);
}

void insertWant(int pos) {
	node* tmp = getN();

	// 빈 리스트인 경우
	if (head == NULL) {
		head = tmp;
		return;
	}

	// 리스트의 맨 앞에 삽입
	if (pos == 1) {
		tmp->next = head;
		head->pre = tmp;
		head = tmp;
		return;
	}

	// 리스트 중간에 삽입
	node* cur = head;
	for (int i = 1; i < pos - 1; i++) {
		cur = cur->next;
	}

	if (cur == NULL) {
		printf("삽입할 위치가 리스트의 크기를 벗어났습니다.\n");
		return;
	}

	tmp->next = cur->next;
	tmp->pre = cur;
	if (cur->next != NULL) {
		cur->next->pre = tmp;
	}
	cur->next = tmp;
	return;
}

int main() {
	int n;
	printf("몇 번 입력?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		//InsertAtHead();
		InsertAtTail();
	}
	printf("3번째 삽입?");
	insertWant(3);
	print();
	delHead();
	printf("\n");
	print();
	delWant(2);
	printf("\n");
	Revprint();


	return 0;
}