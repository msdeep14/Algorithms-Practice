// given inorder and postorder , construct a tree
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *right, *left;
};

node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
}

int search(int in[], int inStart, int inEnd, int x){
	for(int i=inStart; i<=inEnd; i++){
		if(in[i] == x){
			return i;
		}
	}
	return -1;
}

node *buildtree(int in[], int post[], int inStart, int inEnd, int *pindex){
	if(inStart > inEnd) return NULL;
	node *temp = getnode(post[*pindex]);
	(*pindex)--;
	if(inStart == inEnd) return temp;

	int inIndex = search(in, inStart, inEnd, temp->data);
	temp->right = buildtree(in, post, inIndex+1, inEnd,pindex);
	temp->left = buildtree(in,post,inStart,inIndex-1,pindex);
	return temp;  
}

void preorder(node *root){
	if(!root) return;
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}

int main(){
	int in[] = {4,8,2,5,1,6,3,7};
	int post[] = {8,4,5,2,6,7,3,1};
	int pindex = 7;
	node *root = buildtree(in,post,0,7,&pindex);
	for(int i=0;i<8;i++){
		cout<<in[i]<<" ";
	}
	cout<<endl;
	preorder(root);
	cout<<endl;
	return 0;
}