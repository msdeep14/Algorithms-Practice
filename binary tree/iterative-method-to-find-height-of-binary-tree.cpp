//http://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

int findHeight(node *root){
	if(!root) return 0;
	queue<node*> q;
	q.push(root);
	int height = 0;
	while(1){
		int count = q.size();
		if(count == 0) return height;
		
		height += 1;
		while(count > 0){
			node *temp = q.front();
		q.pop();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			count--;
		}
	}
	return height;
}

int main(){
	node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	int height = findHeight(root);
	cout << "height :: " << height << endl;
	return 0;
}
