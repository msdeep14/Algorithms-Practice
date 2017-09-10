// construct linked list
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *getNode(int data){
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}
int main(){
	int x;
	int flag = 0;
	node *head = getNode(3);
	node *temp = head;
	while(true){
		cout << "enter data \n";
		cin>>x;
		temp->next = getNode(x);
		temp = temp->next;
		cout << "enter 1 to continue\n";
		cin>>flag;
		if(!flag)break;
	}
	while(head){
		cout << head->data<<" ";
		head = head->next;
	}
	cout << endl;
	return 0;
}