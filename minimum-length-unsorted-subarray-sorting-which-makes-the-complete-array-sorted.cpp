//http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
//minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    int arr[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left=0;
    int right = n-1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            left = i;
            break;
        }
    }
    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            right = i;
        }
    }
    //sort the elements form left to right;
    //check the array if its sorted
    //if not
    //in 0 to left-1 find the element index greater than arr[left] ->left = newleftindex;
    //in right+1 to n-1 , find the element index smaller than arr[right] ->right = newrightindex

    //if asked sorting, sort the arr
    //return left and right;
    return 0;
}
