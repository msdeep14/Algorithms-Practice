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
	cout << endl;
}

void preorder(Node *root){
	stack<Node *> s;
	s.push(root);
	while(!s.empty()){
		Node *temp = s.top();
		s.pop();
		cout << temp->data << " ";
		if(temp->right) s.push(temp->right);
		if(temp->left) s.push(temp->left);
	}
	cout << endl;
}

void postorder(Node *root){
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		Node *temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left) s1.push(temp->left);
		if(temp->right) s1.push(temp->right);
	}
	while(!s2.empty()){
		Node *temp = s2.top();
		s2.pop();
		cout << temp->data << " ";
	}
	cout << endl;
}

int main(){
	Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	inorder(root);
	preorder(root);
	postorder(root);
	return 0;
}