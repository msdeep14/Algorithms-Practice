// http://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include <bits/stdc++.h>
using namespace std;
void mergeKSorted(int arr[][5000], int n, int k){
	
}
int main(){
	int n,k;
	int arr[5000][5000];
	cin>>n>>k;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	mergeKSorted(arr,n, k);
	return 0;
}