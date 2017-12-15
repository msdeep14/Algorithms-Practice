// http://practice.geeksforgeeks.org/problems/value-equal-to-index-value/0
#include <bits/stdc++.h>
using namespace std;

// 1 based indexing
int search(int arr[], int n){
	int i=1, j = n;
	int mid;
	while(i<j){
		mid = (i+j)/2;
		if(arr[mid] == mid) return mid;
		if(arr[mid] < mid) i = mid+1;
		else j = mid - 1;
	}
	return -1;
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[100];
		for(int i=1;i<=n;i++) cin >> arr[i];
		sort(arr,arr+n+1);
		int index = search(arr,n);
		if(index == -1) cout << "Not Found\n";
		else cout << index << endl;
	}
	return 0;
}