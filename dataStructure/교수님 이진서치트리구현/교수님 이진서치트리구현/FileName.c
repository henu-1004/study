#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
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
		root = getnewnode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else
		root->right = Insert(root->right, data);
	return root;
}

void preprint(node * root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preprint(root->left);
	preprint(root->right);
	return;
}

void Inprint(node* root) {
	if (root == NULL) {
		return;
	}
	Inprint(root->left);
	printf("%d ", root->data);
	Inprint(root->right);
}

void postprint(node* root) {
	if (root == NULL) {
		return;
	}
	postprint(root->left);
	postprint(root->right);
	printf("%d ", root->data);
}

int Search(node* root, int data) {
	if (root == NULL) return 0;
	else if (root->data == data) return 1;
	else if (root->data >= data) {
		return Search(root->left, data);
	}
	else
		return Search(root->right, data);
}

int main() {
	node* root = NULL;
	int num;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 17);
	root = Insert(root, 12);
	preprint(root);
	printf("pre종료 \n");

	Inprint(root);
	printf("In종료 \n");

	postprint(root);
	printf("post종료 \n");

	scanf_s("%d", &num);
	if (Search(root, num)) {
		printf("찾았다: %d\n", num);
	}
	else
		printf("못찼아따.");
	return 0;
}