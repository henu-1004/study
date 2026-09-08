#include<stdio.h>
#include<stdlib.h>

typedef struct Treenode {
	int data;
	struct Treenode* left;
	struct Treenode* right;
}node;

node* getnewnode(int data) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
node* Insert(node* root, int data) {
	if (root == NULL) {
		root= getnewnode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

void inOrder(node* root) {
	if (root = NULL)
		return;
	inOrder(root->left);
	printf("%d", root->data);
	inOrder(root->right);
}

//cur사용해서 하기>>>root만사용해서 실행가능
//int findMin(node* root) {
//	node* cur = root;
//	if (root == NULL) {
//		printf("Error:Tree is empty");
//		return -1;
//	}
//	while (cur->left != NULL) {
//		cur = cur->left;
//	}
//	return cur->data;
//}

int findMint(node* root) {
	if (root == NULL) {
		printf("Error:Tree is Empty");
		return -1;
;	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data;
}
//반복문 활용
int findMax(node* root) {
	if (root == NULL) {
		printf("Error:Tree is empty");
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}
//반복문 활용

//재귀활용
int findMinRec(node* root) {
	if (root == NULL) {
		printf("Error");
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	return findMinRec(root->left);
}

int findMaxRec(node* root) {
	if (root = NULL) {
		printf("Error");
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	return findMaxRec(root->right);	
}
int main() {
	
	return 0;
}