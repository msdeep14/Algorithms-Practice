// http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	int arr[10005];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		int incl = arr[0];
		int excl = 0;
		int en;
		for(int i=1;i<n;i++){
			en = (incl > excl)?incl:excl;
			incl = excl + arr[i];
			excl = en;
		}
		cout << max(excl, incl) << endl;
	}
	return 0;
}