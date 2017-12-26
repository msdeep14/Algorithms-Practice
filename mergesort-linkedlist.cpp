// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

struct  Node{
	int data;
	Node *next;
};

Node *getNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void split(Node *head, Node **front, Node **back){
	if(!head || !head->next){
		*front = head;
		*back = NULL;
	}else{
		Node *slow = head;
		Node *fast = head->next;
		while(fast){
			fast = fast->next;
			if(fast){
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

Node * sortedMerge(Node *a, Node *b){
	if(!a) 
		return b;
	else if(!b)
		return a;
	Node *res = NULL;
	if(a->data <= b->data){
		res = a;
		res->next = sortedMerge(a->next, b); 
	}else{
		res = b;
		res->next = sortedMerge(a, b->next);
	}
	return res;
}

void mergeSort(Node **headRef){
	Node *head = *headRef;
	Node *a, *b;
	if(!head || !head->next)
		return;
	split(head, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*headRef = sortedMerge(a,b);
}

int main(){
	Node *head = getNode(5);
	head->next = getNode(1);
	head->next->next = getNode(7);
	head->next->next->next = getNode(2);
	head->next->next->next->next = getNode(9);
	head->next->next->next->next->next = getNode(3);
	mergeSort(&head);
	Node *p = head;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
}