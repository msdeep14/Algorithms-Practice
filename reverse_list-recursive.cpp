// reverse a linked list recursive

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *getNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void reverse(Node **head){
	if(! (*head)) return;
	Node *first, *rest;
	first = *head;
	rest = first->next;
	if(!rest) return;

	reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

int main(){
	Node *head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->next->next->next = getNode(4);

	reverse(&head);
	Node *p = head;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
}