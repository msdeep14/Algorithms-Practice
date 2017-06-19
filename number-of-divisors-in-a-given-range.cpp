//
//number-of-divisors-in-a-given-range
#include <iostream>
using namespace std;
int main(){
	int m,n,a,b;
	cin>>t;
	while(t--){
		int count = 0;
		cin>>m>>n>>a>>b;
		for(int i=m;i<=n;i++){
			if(i%a == 0 || i%b == 0) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}