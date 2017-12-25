// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <bits/stdc++.h>
using namespace std;

int searchElement(int arr[], int n, int x){
	int l = 0;
	int r = n-1;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(x == arr[mid])
			return mid;
		else if(arr[l] <= arr[mid]){
			if(x >= arr[l] && x <= arr[mid])
				r = mid-1;
			else 
				l = mid+1;
		}
		else{
			if(x >= arr[mid] && x <= arr[r])
				l = mid+1;
			else 
				r = mid-1;
		}
	}
	return -1;
}

int main(){
	int arr[] = {4,5,6,7,0,1,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 4;
	int res = searchElement(arr,n,x);
	cout << "element at index :: " << res << endl;
	return 0;
}