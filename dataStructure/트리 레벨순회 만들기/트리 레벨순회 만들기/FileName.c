#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
}node;

typedef struct Que {
	char data;
	struct Que* next;
	;
}que;

que* getnewQue(que**front, char x) {
	que* tmp = (que*)malloc(sizeof(que));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

node* getnewnode(node*root) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = root->data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void Enque(node*root) {
	que* tmp = getnewQue(root);
	if (root == NULL) {
		root = tmp;
		return;
	}
	else {
		que* cur = root;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = NULL;
		return;
	}
}
void Deque() {

}

//레벨순회
void LevelOrder(node* root) {
	If(root == NULL) return;
	Enque(root);
	While(!IsEmpty()) {
		node* cur = front();//큐 제일앞 데이터
		printf(“data: % c \n”, cur - < data) :
			if (cur->left != NULL)
				Enque(cur->left);
		if(cur->right != NULL)
			Enque(cur->right);
		Deque();//실제 큐에서 제거
	}
}



node* Insert(node* root, char data) {
	if (root == NULL) {
		root = getnewnode(data);
		return;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

void Print(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	Print(root->left);
	Print(root->right);
}

int main() {
	node* root = NULL;
	que* front = NULL;
	int num;
	root = Insert(root, 'F');
	root = Insert(root, 'D');
	root = Insert(root, 'J');
	root = Insert(root, 'B');
	root = Insert(root, 'E');
	root = Insert(root, 'G');
	root = Insert(root, 'K');
	root = Insert(root, 'A');
	root = Insert(root, 'I');
	root = Insert(root, 'H');

	Print(root);

	scanf_s("%d", &num);
	Search(root, num);

	

	return 0;
}

