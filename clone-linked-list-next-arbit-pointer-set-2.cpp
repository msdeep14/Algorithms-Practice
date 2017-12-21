// http://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next, *arbit;
};

Node *newNode(int data){
	Node *temp = new Node();
	temp->next = temp->arbit = NULL;
	return temp;
}

void cloneList(Node *head){
	// create a hashmap
	unordered_map<Node*, Node*> mp;
	// copy the nodes
}

int main(){
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit = head->next->next->next->next;
	head->next->next->next->arbit = head->next->next;
	head->next->next->next->next->arbit = head->next;

	cloneList(head);
	return 0;
}