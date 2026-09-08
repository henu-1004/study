#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;



node * insert(node*head,int data) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		return head;
	}
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	return head;
}

void print(node*head) {
	node* cur = head;
	while (cur != NULL) {
		printf("%d", cur->data);
		cur = cur->next;
		printf("\n");
	}
	printf("\n");
}

node * Reverse(node* p) {
	if (p->next == NULL) {
		return p;
	}
	node*r=Reverse(p->next);
	node* q = p->next;
	q->next = p;
	p->next = NULL;
	return r;
}



int main() {
	int n, data;
	node* head = NULL;
	printf("몇개의 데이터를 입력할것인가?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("숫자입력 :");
		scanf_s("%d", &data);
		head = insert(head, data);
	}
	printf("입력한 숫자들 \n");
	print(head);

	printf("입력한 숫자들 \n");
	head = Reverse(head);
	print(head);

	return 0;
}


