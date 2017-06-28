//http://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0
//
#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int brr[], int n){
    int m1 = arr[n/2];
    int m2 = brr[n/2];
    if(m1 > m2){
        
    }
}
int main(){
    int t,n;
    int arr[10005];
    int brr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        /*
        int i=0,j=0;
        int m1 = -1, m2 = -1;
        for(int k=0;k<=n;k++){
            if(i == n){
                m1 = m2;
                m2 = brr[0];
                break;
            }else if(j == n){
                m1 = m2;
                m2 = arr[0];
                break;
            }
            else if(arr[i]<brr[j]){
                m1 = m2;
                m2 = arr[i];
                i++;
            }
            else{
                m1 = m2;
                m2 = brr[j];
                j++;
            }
        }
        cout<<(m1+m2)<<endl; */
        int ans = -1;
        int m1 = arr[n/2];
        int m2 = brr[n/2];
        if(m1 == m2){
            ans = m1 + m2;
        }else{
            search(arr,brr,n);
        }
    }
    return 0;
}
