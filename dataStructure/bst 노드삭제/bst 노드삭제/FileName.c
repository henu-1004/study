#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* Delete(node* root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) {
		root->left
	}
}