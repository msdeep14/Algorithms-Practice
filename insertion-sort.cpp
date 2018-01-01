// insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
	int i, j,current;
	for(i=1;i<n;i++){
		current = arr[i];
		for(j=i-1;j>=0;j--){
			if(arr[j]>current){
				arr[j+1] = arr[j];
			}else
				break;
		}
		arr[j+1] = current;
	}
}

int main(){
	int arr[] = {5,1,3,7,10,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr,n);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}