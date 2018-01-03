// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	stack<string> st;
	// cin>>s;
	char str[1000];
	cin.getline(str,sizeof(str));
	// const char *str = s.c_str();
	char *pch;
	pch = strtok(str," ");
	// cout << str << endl;
	while(pch){
		st.push(pch);
		cout << pch << " ";
		pch = strtok(NULL," ");
	}
	while(!st.empty()){
		cout << st.top() << " ";
		cout << endl;
		st.pop();
	}
	return 0;
}