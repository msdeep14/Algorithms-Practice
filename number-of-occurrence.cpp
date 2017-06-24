//http://practice.geeksforgeeks.org/problems/number-of-occurrence/0
//number-of-occurrence
#include<bits/stdc++.h>
using namespace std;
int left,right;
void search(int arr[],int n,int x,int low,int high){
    if(arr[low]==x && arr[right]==x){
        
    }
}
int main(){
    int t,n,x;
    int arr[305];
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        search(arr,n,x,0,n-1);
    }
}
