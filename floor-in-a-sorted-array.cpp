// http://www.geeksforgeeks.org/floor-in-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int x){
    int i=0;
    int j=n-1;
    int prev = -1;
    if(arr[n-1] <= x) return (n-1);
    if(arr[0] > x) return -1;
    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid]>x){
            j = mid-1;
        }else if(arr[mid] < x){
            prev = mid;
            i = mid+1;
        }
    }
    return prev;
}
int main(){
    int t,n,x;
    int arr[1005];
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = search(arr,n,x);
        cout<<ans<<endl;
    }
    return 0;
}
