// power set
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int arr[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int psize = pow(2,n);
	for(int i=0;i<psize;i++){
		cout << "{";
		for(int j=0;j<n;j++){
			if(i & (1<<j)) cout << arr[j] <<", "; 
		}
		cout << "}\n";
	}
	return 0;
}