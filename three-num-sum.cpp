/*
Given array of integers you have to find 3 no’s such that sum of two makes the other in minimum time complexity.
*/

// CPP program to find three numbers
// such that sum of two makes the 
// third element in array
#include <bits/stdc++.h>
using namespace std;

// utility function for finding 
// triplet in array
void findTriplet(int arr[], int n){
	// sort the array
	sort(arr, arr+n);

	// for every element in arr
	// check if a pair exist(in array) whose
	// sum is equal to arr element
	int i, j = 0, k = n-1;
	for(i = n-1; i >= 0; i--){
		j = 0;
		k = i-1;
		while(j < k){
			if(arr[i] == arr[j] + arr[k]){
				// pair found
				cout << "numbers are " << arr[i] << " "
				<< arr[j] << " " << arr[k] << endl;
				return;
			}
			else if(arr[i] > arr[j] + arr[k])
				j += 1;
			else
				k -= 1;
		}
	}

	// no such triplet is found in array
	cout << "No such triplet exist\n";
}

// driver program
int main(){
	int arr[] = {5,32,1,7,10,50,19,21,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	findTriplet(arr,n);
	return 0;
}