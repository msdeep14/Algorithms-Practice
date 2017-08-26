// http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
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

int findMaxPath(node *root, int *mx){
	if(!root) return 0;
	int l = findMaxPath(root->left,mx);
	int r = findMaxPath(root->right, mx);

	int mx1 = max(max(l,r)+root->data,root->data);

	int mx2 = max(mx1,l+r+root->data);
	*mx = max(*mx,mx2);
	return mx1;
}

int main(){
	node *root = getnode(10);
	root->left = getnode(2);
	root->right = getnode(10);
	root->left->left = getnode(20);
	root->left->right = getnode(1);
	root->right->right = getnode(-25);
	root->right->right->left = getnode(3);
	root->right->right->right = getnode(4);
	int mx = INT_MIN;
	findMaxPath(root,&mx);
	cout << "max path :: " << mx << endl;
	return 0;
}
