// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
#include <bits/stdc++.h>
using namespace std;

int check(string inp){
	stack<char> st;
	for(int i=0;i<inp.length();i++){
		if(inp[i] == '(' || inp[i] == '[' || inp[i] == '{'){
			st.push(inp[i]);
		}else{
			if(inp[i] == ')' && st.top() == '('){
				st.pop();
			}else if(inp[i] == ']' && st.top() == '['){
				st.pop();
			}else if(inp[i] == '}' && st.top() == '{'){
				st.pop();
			}else{
				return 0;
			}
		}
	}
	if(st.empty()){
		return 1;
	}
	return 0;
}

int main(){
	string s;
	cin>>s;
	if(check(s))
		cout << "balanced\n";
	else
		cout << "not balanced\n";
	return 0;
}