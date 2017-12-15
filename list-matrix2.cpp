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

// CPP program to construct a linked list
// from given 2D matrix
#include <bits/stdc++.h>
using namespace std;

// struct node of linked list
struct node{
	int data;
	node *right, *down;
};

// returns head pointer of linked list
// constructed from 2D matrix
node *construct(int arr[][3], int i, int j, int m, int n){
	// return if i or j is out of bounds
	if(i > n-1 || j > m-1) return NULL;

	// create a new node for current i and j
	// and recursively allocate its down and 
	// right pointers
	node *temp = new node();
	temp->data = arr[i][j];
	temp->right = construct(arr, i, j+1, m, n);
	temp->down = construct(arr, i+1, j, m, n);
	return temp;
}

// utility function for displaying
// linked list data
void display(node *head){
	// pointer to move right
	node *Rp;

	// pointer to move down
	node *Dp = head;

	// loop till node->down is not NULL
	while(Dp){
		Rp = Dp;

		// loop till node->right is not NULL
		while(Rp){
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		cout << "\n";
		Dp = Dp->down;
	}
}

// driver program
int main(){
	// 2D matrix
	int arr[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	
	int m = 3, n = 3;
	node *head = construct(arr,0,0,m,n);
	display(head);
	return 0;
}
