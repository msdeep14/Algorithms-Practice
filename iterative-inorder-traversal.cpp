// iterative inorder traversal

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node *getNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(Node *root){
	stack<Node *> s;
	s.push(root);
	root = root->left;
	while(1){
		while(root){
			s.push(root);
			root = root->left;
		}

		if(!root && !s.empty()){
			Node *temp = s.top();
			s.pop();
			cout << temp->data << " ";
			root = temp->right;
		}
		if(!root && s.empty())
			break;
	}
}

int main(){
	Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	inorder(root);
	return 0;
}