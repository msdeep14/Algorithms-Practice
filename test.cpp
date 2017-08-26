#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 16;
	string res;
	while(n>0){
		char ch = n%2 + 48;
		//cout<< ch<<" ";
		res.push_back(ch);
		n/=2;
	}
	reverse(res.begin(),res.end());
	cout << res << endl;
	return 0;
}