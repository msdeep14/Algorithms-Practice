// http://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size/0
#include <bits/stdc++.h>
using namespace std;

void maxOfMin(int arr[], int n){
	int left[n+1];
	int right[n+1];
	for(int i=0;i<=n;i++){
		left[i] = -1;
		right[i] = n;
	}
	// calculate left and right values
	stack<int> s;
	for(int i=0;i<n;i++){
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			left[i] = s.top();
		s.push(i);
	}
	while(!s.empty()) s.pop();

	for(int i=n-1;i>=0;i--){
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			right[i] = s.top();
		s.push(i);
	}

	int ans[n+1] = {0};
	for(int i=0;i<n;i++){
		int len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], arr[i]);
	}

	for(int i=n-1;i>=1;i--){
		ans[i] = max(ans[i], ans[i+1]);
	}
	for(int i=1;i<=n;i++){
		cout << ans[i] << " "; 
	}
	cout << endl;
}


int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[1000];
		for(int i=0;i<n;i++) cin>>arr[i];
		maxOfMin(arr,n);
	}
	return 0;
}