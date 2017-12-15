// 
#include <bits/stdc++.h>
using namespace std;
struct  node
{
	int data;
	node *next;
};
node *getnode(int data){
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void modifyLinkedList(node **head){
	node *p = *head;
	node *prev = *head;
	node *prev1 = NULL;
	int x = 0;
	while(p){
		if(p->data != 0){
			x += p->data;
		}else{
			// delete node from prev to 
			// all the nodes before p
			while(p != prev){
				// delete prev and move to next node
				node *temp = prev;
				
			}
		}
	}
}

int main(){
	node *head = getnode(7);
	head->next = getnode(3);
	head->next->next = getnode(0);
	head->next->next = getnode(2);
	head->next->next->next = getnode(0);
	head->next->next->next->next = getnode(1);
	head->next->next->next->next->next = getnode(5);
	modifyLinkedList(&head);
	return 0;
}