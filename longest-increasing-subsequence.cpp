//http://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int lis[10005];
        lis[0] = 1;
        int mx = -INT_MAX;
        for(int i=1;i<n;i++){
            mx = -INT_MAX;
            for(int j = i-1;j>=0;j--){
                if(arr[j]>arr[i] && lis[j] > mx){
                    mx = lis[j];
                }
            }
            lis[i] = max(1,mx);
        }
        mx = -INT_MAX;
        for(int i=0;i<n;i++){
            if(lis[i]>mx){
                mx = lis[i];
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
