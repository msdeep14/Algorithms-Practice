//http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
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

void findMax(node *root,int *mx, int curr){
	if(!root) return;
	curr= curr + root->data;
	if(!root->left && !root->right){
		if(curr > *mx){
			*mx = curr;
		}
	}
	findMax(root->left,mx,curr);
	findMax(root->right,mx,curr);
}

void findMaxPath(node *root, int *mx,int curr){
	if(!root) return;
	int mx2 = INT_MIN;
	int mx3 = INT_MIN;
	findMax(root->left,&mx2,0);
	findMax(root->right,&mx3,0);
	curr = mx2 + mx3;
	if(curr > *mx){
		*mx = curr;
	}
	findMaxPath(root->left,mx,curr);
	findMaxPath(root->right,mx,curr);
}

int main(){
	node *root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->left = getnode(6);
	root->left->right = getnode(5);
	int mx = INT_MIN;
	findMaxPath(root,&mx,0);
	cout << "max path :: " << mx << endl;
	return 0;
}