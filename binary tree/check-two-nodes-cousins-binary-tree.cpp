// http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/
#include <bits/stdc++.h>
using namespace std;

// struct node of binary tree
struct node{
	int data;
	node *left, *right;
};

// return new node 
node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
}

int checkIfSibling(node *root, int p1, int p2){
	if(!root) return 0;
	if(root->left && root->right){
		if((root->left->data == p1 && root->right->data == p2) ||
			(root->left->data == p2 && root->right->data == p1)) return 1;
	}
	return (checkIfSibling(root->left,p1,p2) || checkIfSibling(root->right,p1,p2));
}

int checkCousin(node *root, int p1, int p2){
	int a = -1, b = -1;
	queue<node*> q;
	if(!root) return 0;
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		a = -1, b = -1;
		while(size--){
			node *temp = q.front();
			q.pop();
			if(temp->data == p1)
				a = 1;
			else if(temp->data == p2)
				b = 1;
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right); 
		}
		if(a == 1 && b == 1 && !checkIfSibling(root,p1,p2))
			return 1;
	}
	return 0;
}

int main(){
	//contruct binary tree
	node *root = getnode(1);
	root->left = getnode(2);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	root->left->left->right = getnode(2);
	root->right = getnode(3);
	root->right->right = getnode(8);
	root->right->right->left = getnode(6);
	root->right->right->right = getnode(7);

	int p1 = 4, p2 = 8;
	if(checkCousin(root,p1,p2)) cout << "yes\n";
	else cout << "No\n";
	
	return 0;
}