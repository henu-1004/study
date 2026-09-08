#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;

void insert() {
	node* tmp = (node*)malloc(sizeof(node));
	printf("숫자입력 : ");
	tmp->next = NULL;
	scanf_s("%d", &tmp->data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
}

void print() {
	printf("입력한 숫자들 \n");
	node* cur = head;
	while (cur != NULL) {
		printf("%d", cur->data);
		cur = cur->next;
		printf("\n");
	}
	printf("\n");
}

void delTail() {
	node* del = head;
	node* pre=NULL;
	if (head == NULL) {
		return;
	}
	while (del->next != NULL) {
		pre = del;
		del = del->next;
	}
	if (head->next == NULL) {
		free(del);
		head = NULL;
		return;
	}

	pre->next = NULL;	
	free(del);
}


//모든노드 삭제
void delall() {
	node* del = head;
	while (head != NULL) {
		head = del->next;
		free(del);
		del = head;
	}
}

void delWant() {
	node* Dpre = head;
	int n;
	printf("삭제 할 위치");
	scanf_s("%d", &n);
	if (n == 1) {
		head = Dpre->next;
		free(Dpre);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		Dpre = Dpre->next;
	}
	node* del = Dpre->next;
	Dpre->next = del->next;
	free(del);

}

//원하는 위치 삭제
void deWant(int n) {
	node* Dpre = head;
	if (n == 1) {
		head = Dpre->next;
		free(Dpre);
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		Dpre = Dpre->next;
	}
	node* del = Dpre->next;
	Dpre->next = del->next;
	free(del);
}

void del() {
	node* del = head;
	head = del->next;
	free(del);
} //맨앞노드삭제

int main() {
	int n;
	printf("몇개의 데이터를 입력할것인가?");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		insert();
	}
	
	delTail();
	del();
	print();
	delWant();
	print();
	deWant(1);
	print();
	delall();
	print();
	return 0;
}


