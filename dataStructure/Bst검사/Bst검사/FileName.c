#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}node;

int IsSubtreeLesser(node* root, int value) {
	if (root == NULL) {
		return 1;
	}
	if (root->data <= value 
		&& IsSubtreeLesser(root->left, value) 
		&& IsSubtreeLesser(root->right, value)) {
		return 1;}
	else
		return 0;
}
int IsSubtreeGreater(node* root, int value);

int IsBstree(node* root) {
	if (root == NULL) {
		return 1;
	}
	if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data)
		&& IsBstree(root->left) && IsBstree(root->right))
		return 1;
	else
		return 0;
}

int IsBstreeUtil(node* root,int minvalue, int maxvalue) {
	if (root == NULL) {
		return 1;
	}
	if (root->data>minvalue&&root->data<maxvalue
		&& IsBstree(root->left) && IsBstree(root->right))
		return 1;
	else
		return 0;
}