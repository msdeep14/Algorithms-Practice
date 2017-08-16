/*
Given a matrix. Convert it into a linked list matrix such that each node is connected to its next right and down node.

Ex:
1 2 3
4 5 6
7 8 9

Output:
1->2->3->NULL
|  |  |
v  v  v
4->5->6->NULL
|  |  |
v  v  v
7->8->9->NULL
|  |  |
v  v  v
--NULL-

http://www.geeksforgeeks.org/factset-interview-experience-set-9-campus-full-time/
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *right, *down;
};

// utility function
// returns new node of type node
node *newnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	return temp;
}

node *construct(int arr[][3]){
	int n = 3, m = 3;
	node *head = newnode(arr[0][0]);
	node *p = head;
	node *temp;// = p->down;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//if(j != m-1){
				if(j != m-1) p->right = newnode(arr[i][j+1]);
				if(i != n-1) p->down = newnode(arr[i+1][j]);
				if(j == 0){
					temp = p->down;
				}
				p = p->right;
			//}
			if(j == m-1 && i == n-1){
                break;
			}
			else if(j == m-1){
				p = temp;
				if(temp->down) temp = temp->down;
			}
		}
	}
	return head;
}

// utility function for
// display of linked list
void display(node *head){
	node *p = head;
	node *temp = NULL;
	if(p->down) temp = p->down;
	while(p->down || p->right){
		cout << p->data;
		if(p->right){
			p = p->right;
			cout << " ";
		}else if(p->down){
			p = temp;
			if(temp->down) temp = temp->down;
			cout << endl;
		}
	}
}

// driver program
int main(){
	int arr[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	node *head = construct(arr);
	display(head);
	return 0;
}
