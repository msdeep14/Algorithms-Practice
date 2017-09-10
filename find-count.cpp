#include<iostream>
using namespace std;
int bLeft(int arr[], int n, int x){
    int i = 0, j = n-1;
    int mid;
    while(i < j){
        mid = (i+j)/2;
        if(arr[mid] == x){
            if(mid>0 && arr[mid-1]!=x) return mid;
            else if(mid == 0) return mid;
            else j = mid-1;
        }
        else if(arr[mid] < x) j = mid-1;
        else i = mid+1;
    }
    return -1;
}

int bRight(int arr[], int n, int x){
    int i=0,j=n-1;
    int mid;
    while(i < j){
        if(arr[mid] == x){
            if(mid<n-1 && arr[mid+1] != x) return mid;
            else if(mid == n-1) return mid;
            else i = mid + 1;
        }
        else if(arr[mid] < x) j = mid -1;
        else i = mid + 1;
    }
    return -1;
}
int main()
 {
	//code
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    int arr[500];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    int l = bLeft(arr,n,x);
	    int r = bRight(arr,n,x);
	    cout << l << " " << r << endl;
	    cout << (l-r+1) << endl;
	}
	return 0;
}