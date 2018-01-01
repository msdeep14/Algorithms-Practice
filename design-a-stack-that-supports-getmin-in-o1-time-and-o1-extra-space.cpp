// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
#include <bits/stdc++.h>
using namespace std;
int minEle = INT_MAX;
void push(stack<int> &s, int x){
	if(s.empty()){
		s.push(x);
		minEle = x;
		return;
	}
	if(x >= minEle){
		s.push(x);
	}else{
		s.push(2*x - minEle);
		minEle = x;
	}
}

void pop(){
	if(s.empty()){
		cout << "stack empty\n";
		return;
	}
	int y = s.top();
	if(y>=minEle){
		s.pop();
	}else{
		minEle = 2*minEle - y;
		s.pop();
	}
}

int main(){
	int x,y;
	stack<int> s;
	while(1){
		switch(ch){
			case 1: 
				cin>>x;
				push(s,x);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				cout << "min ele is :: " << minEle << endl;
				break;
			default:
				cout << "wrong input \n";
				break;
		}
	}
	return 0;
}