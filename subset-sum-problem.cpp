// https://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
#include <bits/stdc++.h>
using namespace std;

int isSubset(int arr[], int n, int sum){
	if(n == 0 && sum != 0) return 0;
	if(sum == 0) return 1;
	if(sum < arr[n-1]) return isSubset(arr, n-1, sum);
	return isSubset(arr,n-1,sum) || isSubset(arr,n-1,sum-arr[n-1]);
}

int isSubsetDP(int arr[], int n, int sum){
	int dp[n+1][sum+1];
	
}

int main(){
	int n;
	int arr[1000];
	cin>>n;
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if(sum%2 != 0){
		cout << "not possible \n";
		return 0;
	}
	sum = sum/2;
	int res = isSubset(arr,n,sum);
	(res == 1) ?(cout << "possible\n"):(cout << "not possible \n");
	return 0;
}