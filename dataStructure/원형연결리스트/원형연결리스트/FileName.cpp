#include<stdio.h>
#include<stdlib.h>
//원형이중연결리스트
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}node;

node* head=NULL;

node* GetNewnode() {
	node* tmp = (node*)malloc(sizeof(node));
	printf("입력할 수 : ");
	scanf_s("%d", &tmp->data);
	tmp->pre = NULL;
	tmp->next = NULL;
	return tmp;
}

void Insert() {
	node* tmp = GetNewnode();
	if (head == NULL) {
		head = tmp;
		tmp->pre = head;
		tmp->next = head;
		return;
	}
	head->pre->next = tmp;
	tmp->pre = head->pre;
	head->pre = tmp;
	tmp->next = head;
}

void print() {
	printf("정방향출력");
	node* cur=head;
	while (cur->next != head) {
		printf(" %d ", cur->data);
		cur = cur->next;
	}
	printf("%d", cur->data);
	printf("\n");
	return;
}

void Rvprint() {
	printf("역방향출력");
	node* cur = head->pre;
	while (cur != head) {
		printf(" %d ", cur->data);
		cur = cur->pre;
	}
	printf("%d", cur->data);
	printf("\n");
	return;
}

int main() {
	int n;
	printf("몇 번 입력?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		Insert();
	}
	print();
	Rvprint();


	return 0;
}