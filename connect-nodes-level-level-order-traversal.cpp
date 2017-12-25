// https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/
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

void connect(Node *temp){
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();
		if(temp){
			temp->nextRight = q.front();
			if(temp->left) 
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}else if(!q.empty()){
			q.push(NULL);
		}
	}
}

int main(){
	Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(8);
	connect(root);
	return 0;
}