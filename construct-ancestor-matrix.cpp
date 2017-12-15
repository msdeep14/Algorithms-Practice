// construct ancestor matrix
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
int mat[50][50];
int mx = -INT_MAX;
node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void form(node *root,int x){
	if(!root) return;
	//int x = root->data;
	mx = max(mx,x);
	if(root->left) {
		mat[x][root->left->data] = 1;
		mx = max(mx,root->left->data);	
	}
	if(root->right){
		mat[x][root->right->data] = 1;
		mx = max(mx,root->right->data);
	}
	form(root->left,x);
	form(root->right,x);
}

void traverse(node *root){
	if(root == NULL) return;
	 int x = root->data;
	form(root,x);
	traverse(root->left);
	traverse(root->right);
}
int main(){
	node *root = getnode(5);
	root->left = getnode(1);
	root->right = getnode(2);
	root->left->left = getnode(0);
	root->left->right = getnode(4);
	root->right->left = getnode(3);
	traverse(root);
	for(int i=0;i<=mx;i++){
		for(int j=0;j<=mx;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}