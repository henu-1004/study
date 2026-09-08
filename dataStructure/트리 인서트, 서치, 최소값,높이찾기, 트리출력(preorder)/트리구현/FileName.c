#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
}tree;



tree* getnewnode(int x) {
	tree* tmp = (tree*)malloc(sizeof(tree));
	tmp->data = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp; 
}
	


tree* Insert(tree* root, int data) {
	if (root == NULL) {
		root = getnewnode(data);
		return;
	}
	else if(data<=root->data){
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}
//cur 대신 root만 써도됨>>root를 콜바이밸류로 불러왔으니까>>root는 로컬변수임.
//반복문 최소값
int FindMin(tree* root) {
	if (root == NULL) {
		printf("errot:Tree is empty\n");
		return -1;
	}
	tree* cur = root;
	while (cur->left != NULL) {
		cur = cur->left;
	}
	return cur->data;
}
//재귀로 최소값구하기.
int FindMinRec(tree* root) {
	if (root == NULL) {
		printf("errot:Tree is empty\n");
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	return FindMinRec(root->left);
}

void Search(tree* root, int data) {
	if (root == NULL) {
		printf("Not Found\n");
	}
	else if (root->data == data) {
		printf("Found\n");
	}
	else if (root->data > data) {
		Search(root->left, data);
	}
	else if (root->data < data) {
		Search(root->right, data);
	}
 }

void Print(tree* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	Print(root->left);
	Print(root->right);
}

int Max(int a, int b){
	return (a > b) ? a : b;
}

int FindHeight(tree* root) {
	if (root == NULL)
		return -1;
	return Max(FindHeight(root->left), FindHeight(root->right)) + 1;
}



int main() {
	tree* root = NULL;
	int num;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 17);
	root = Insert(root, 12);
	root = Insert(root, 2);
	root = Insert(root, 1);

	Print(root);

	scanf_s("%d", &num);
	Search(root, num);

	printf("Min Rec: %d\n", FindMinRec(root));
	printf("Min While: %d\n", FindMin(root));
	int left = FindHeight(root->left);
	int right = FindHeight(root->right);
	if (left >= right) {
		printf("leftHeight\n");
	}
	else
		printf("rightHeight\n");
	printf("Height: %d\n", FindHeight(root));

	return 0;
}