// http://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/
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

void kDistant(node *root, int path[], int visited[], int len, int k){
	if(!root) return;
	path[len] = root->data;
	visited[len] = 0;
	len++;

	if(root->left == NULL && root->right == NULL && len-k-1>=0 && visited[len-k-1] == 0){
		cout << path[len-k-1]<<" ";
		visited[len-k-1]  = 1;
		return;
	}
	kDistant(root->left,path,visited,len,k);
	kDistant(root->right, path, visited,len, k)	;
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

	// variable to store sum of right leaves
	int visited[1000];
	int path[1000];
	int k = 1;
	kDistant(root,path,visited,0,k);
	cout<<endl;
	return 0;
}