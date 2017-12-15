//http://www.geeksforgeeks.org/find-the-first-missing-number/
//find-the-first-missing-number
#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n){
    int low = 0;
    int high = n-1;
    while(low<high){
        int mid = (low+high)/2;
        if(arr[mid] != mid){
            high = mid-1;
        }else if(arr[mid] == mid && arr[mid+1] != mid+1){
            return mid+1;
        }else{
            low = mid+1;
        }
    }
    return n;
}
int main(){
    int n,t,m;
    cin>>n>>m;
    int arr[100005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x = search(arr,n);
    cout<<x<<endl;
    return 0;
}
