#include<stdio.h>
#define _CRT_SECURE_NO_WARNNINGS
#define max 10

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* getnewnode(int x) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void Insert(node** root, int data) {
	node* tmp = getnewnode(data);
	if (*root == NULL) {
		*root = tmp;
		return;
	}
	node* cur = *root;
	while (1) {
		if (cur->left == NULL && tmp->data < cur->data) {
			cur->left = tmp;
			return;
		}
		else if (cur->right == NULL && tmp->data > cur->data) {
			cur->right = tmp;
			return;
		}
		if (tmp->data < cur->data) {
			cur = cur->left;
		}
		else if (tmp->data > cur->data) {
			cur = cur->right;
		}
		return;
	}



}



int main() {
	node* root = NULL;

}