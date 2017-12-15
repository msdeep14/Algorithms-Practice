// CPP program to print
// all nodes of level k
// iterative approach
/*
binary tree
root is at level 1

                20
              /   \
            10    30
           / \    / \
          5  15  25  40
             /
            12
*/
#include <iostream>
#include <queue>
using namespace std;

// node of binary tree
struct node{
	int data;
	node *left;
	node *right;
};

// utility function to create
// a new node
node * getnode(int data){
	node * newnode = new node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

// utility function to return level of given node
int printkdistant(node *root, int klevel){
	queue<node*> q;
	int level = 1;
	int flag = 0;
	q.push(root);
	// extra NULL is pushed to keep track
	// of all the nodes to be pushed before
	// level is incremented by 1
	q.push(NULL);
	while(!q.empty()){
		node *temp = q.front();
		// print when level is equal to k
		if(level == klevel && temp != NULL){
			flag = 1;
			cout << temp->data << " "; 
		}
		q.pop();
		if(temp == NULL){
			if(q.front())q.push(NULL);
			level +=1;
			// break the loop if level exceeds
			// level given upto which program 
			// has to traverse
			if(level > klevel){
				break;
			}
		}
		else{
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	cout << endl;
	if(flag == 0)
		return 0;
	else return 1;
}
int main(){
	// create a binary tree
	int x;
	cout<<"enter x::\n";
	cin>>x;
	cout<<"out::"<<x<<endl;
	node *root = getnode(20);
	root->left = getnode(10);
	root->right = getnode(30);
	root->left->left = getnode(5);
	root->left->right = getnode(15);
	root->left->right->left = getnode(12);
	root->right->left = getnode(25);
	root->right->right = getnode(40);

	// return level of node
	cout << "data at level 1 : ";
	int ret = printkdistant(root, 1);
	if(ret == 0) cout << "levels in tree are less than number you given" << endl;
	cout << "data at level 2 : ";
	ret = printkdistant(root, 2);
	if(ret == 0) cout << "levels in tree are less than number you given" << endl;
	cout << "data at level 3 : ";
	ret = printkdistant(root, 3);
	if(ret == 0) cout << "levels in tree are less than number you given" << endl;
	cout << "data at level 6 : ";
	ret = printkdistant(root,6);
	if(ret == 0) cout << "levels in tree are less than number you given" << endl;
	return 0;
}