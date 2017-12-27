// https://www.geeksforgeeks.org/flattening-a-linked-list/

// reverse a linked list recursive

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *down;
	Node *right;
};

Node *getNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->down = temp->right = NULL;
	return temp;
}

Node *merge(Node *a, Node *b){
	if(!a)
		return b;
	if(!b)
		return a;
	Node *res = NULL;
	if(a->data <= b->data){
		res = a;
		res->down = merge(a->down,b);
	}else{
		res = b;
		res->down = merge(a, b->down);
	}
	return res;
}

Node *flatten(Node *root){
	if(!root || !root->right)
		return root;
	return merge(root, flatten(root->right));
}


int main(){
	Node *root = getNode(5);
	root->right = getNode(10);
	root->right->right = getNode(19);
	root->right->right->right = getNode(28);
	root->down = getNode(7);
	root->down->down = getNode(8);
	root->down->down->down = getNode(30);
	root->right->down = getNode(20);
	root->right->right->down = getNode(22);
	root->right->right->down->down = getNode(50);
	root->right->right->right->down = getNode(35);
	root->right->right->right->down->down = getNode(40);
	root->right->right->right->down->down->down = getNode(45);

	flatten(root);
	Node *p = root;
	while(p){
		cout << p->data << " ";
		p = p->down;
	}
}