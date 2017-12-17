// http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
#include <bits/stdc++.h>
using namespace std;

void partision(int arr[], int n){
	int i = -1;
	int pivot = 0;
	for(int j=0;j<n;j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
}

int main(){
	int t,n;
	int arr[100005];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		partision(arr,n);
		// for(int i=0;i<n;i++) cout << arr[i]<<" ";
		// now run the loop to
		// swap the positive and negative numbers
		cout << endl;
	}
	return 0;
}