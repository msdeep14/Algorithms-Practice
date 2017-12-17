#include <bits/stdc++.h>
using namespace std;

int partision(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low; j<high;j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	i++;
	swap(arr[i],arr[high]);
	return i;
}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int p = partision(arr,low,high);
		quicksort(arr,low,p-1);
		quicksort(arr,p+1,high);
	}
}

int main(){
	int n;
	int arr[1000];
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	quicksort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
}