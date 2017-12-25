// https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right, *nextRight;
};

Node *getNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = temp->nextRight = NULL;
	return temp;
}

void correct(Node *root, Node **first, Node **middle, Node **last, Node **prev){
	if(!root) return;
	correct(root->left,first,middle,last,prev);
	if(*prev && root->data < (*prev)->data){
		if(!*first){
			*first = *prev;
			*middle = root;
		}else
			*last = root;
	}
	*prev = root;
	correct(root->right,first,middle,last,prev);
}

void inorder(Node *root){
	if(!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


int main(){
	Node *root = getNode(10);
	root->left = getNode(5);
	root->right = getNode(8);
	root->left->left = getNode(2);
	root->left->right = getNode(20);
	Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
	correct(root, &first, &middle, &last, &prev);
	if(first && last)
		swap((first->data), (last->data));
	else if(first && middle)
		swap((first->data), (middle->data));
	inorder(root);
	return 0;
}