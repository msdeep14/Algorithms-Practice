//http://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int sum = 0;
        int flag = 0;
        for(int k=0;k<n && flag==0;k++){
            sum = arr[k];
            int i=0, j=n-1;
            while(i<j && flag ==0){
                sum= arr[k]+arr[i]+arr[j];
                if(x == sum && i!=k && j!=k && i!=j){
                    cout<<"1\n";
                    flag = 1;
                }else if(sum < x && i!=k && j!=k && i!=j){
                    i++;
                }else if(sum > x && i!=k && j!=k && i!=j){
                    j--;
                }else if(i == k){
                    i++;
                }
                else if(j == k ){
                  j--;
                }

            }
        }
        if(flag == 0) cout<<"0\n";
    }
    return 0;
}
