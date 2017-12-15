//http://www.geeksforgeeks.org/segregate-even-and-odd-numbers/
//segregate-even-and-odd-numbers
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left =0;
    int right = n-1;
    while(left < right){
        while(arr[left]%2 == 0 && left<right)
            left++;
        while(arr[right]%2 != 0 && left < right) right --;
        if(left<right){
            swap(arr[left],arr[right]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
