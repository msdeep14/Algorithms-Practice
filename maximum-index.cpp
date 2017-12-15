//http://practice.geeksforgeeks.org/problems/maximum-index/0
//maximum-index
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[1005];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int lmin[1005], rmax[1005];
        lmin[0] = arr[0];
        int mn = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<mn){
                mn = arr[i];
            }
            lmin[i] = mn;
        }
        rmax[n-1] = arr[n-1];
        int mx = arr[n-1];
        for(int i = n-2;i>=0;i--){
            if(arr[i] > mx){
                mx = arr[i];
            }
            rmax[i] = mx;
        }
        int i=0, j = 0, maxdiff = -1;
        while(i < n && j < n){
            if(rmax[j] >= lmin[i]){
                maxdiff = max(maxdiff, j-i);
                j++;
            }
            else i++;
        }
        cout<<maxdiff<<"\n";
    }
    return 0;
}
