#include<stdio.h>
#include<stdlib.h>

//해야하는거-- 앞에서부터 데이터 넣기, 특정부분에 삽입하기, 특정위치 데이터 삭제하기
//전역변수사용하기, 지역변수 사용하기, 함수의 리턴을 안해보기(포인터사용).
//insert함수, print함수, Node 구조체 생성


//1.앞에서부터 데이터 넣기 && 전역변수사용하기

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* head = NULL;

void insert(node*head, int data) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	if (head != NULL) {
		tmp->next=head;
		head = tmp;
	}
	
}
