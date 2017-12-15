//http://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0
//maximum-value-in-a-bitonic-array
#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        int mid = (i+j)/2;
        if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }else if(arr[mid]<arr[mid-1]){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[105];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x = search(arr,n);
        cout<<x<<endl;
    }
    return 0;
}
