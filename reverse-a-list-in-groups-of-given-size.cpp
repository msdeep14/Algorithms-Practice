// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
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

Node * reverseGroup(Node *head, int k){
	if(!head || !head->next) return head;
	stack<Node *> s;
	Node *p = head, *prev = NULL;
	while(p){
		int count = 0;
		while(p && count < k){
			s.push(p);
			p = p->next;
			count += 1;
		}

		while(!s.empty()){
			if(!prev){
				prev = s.top();
				s.pop();
				head = prev;
			}else{
				prev->next = s.top();
				s.pop();
				prev = prev->next;
			}
		}
	}
	prev->next = NULL;
	return head;
}

Node *reverseRec(Node *head, int k){
	Node *p = head;
	Node *prev = NULL, *temp = NULL;
	int count = 0;
	while(count < k && p){
		temp = p->next;
		p->next = prev;
		prev = p;
		p = temp;
		count +=1;
	}
	if(temp)
		head->next = reverseRec(temp, k);
	return prev;
}

int main(){
	int k = 3;
	Node *head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->next->next->next = getNode(4);
	head->next->next->next->next = getNode(5);
	head->next->next->next->next->next = getNode(6);
	head->next->next->next->next->next->next = getNode(7);
	head->next->next->next->next->next->next->next = getNode(8);
	Node * res = reverseRec(head, k);
	Node *p = res;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}