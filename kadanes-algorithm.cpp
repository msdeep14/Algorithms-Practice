//http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
//
#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
    int max_ending_here = 0 , max_so_far = -INT_MAX;
    for(int i=0;i<n;i++){
        max_ending_here += arr[i];
        if(max_ending_here < 0){
            max_ending_here = 0;
        }
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        int ncount = 0;
        int mx = -INT_MAX;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<0) ncount++;
            if(arr[i]>mx)mx = arr[i];
        }
        if(ncount == n){
            cout<<mx<<endl;
        }
        else{
        int res = kadane(arr,n);
        cout<<res<<endl;
        }
    }
    return 0;
}
