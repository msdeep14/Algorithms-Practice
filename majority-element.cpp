//http://practice.geeksforgeeks.org/problems/majority-element/0
//majority-element
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[105];
        int count[101];
        for(int i=0;i<101;i++){
            count[i] = 0;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
            count[arr[i]]++;
        }
        int max = -INT_MAX;
        int res = 0;
        for(int i=0;i<101;i++){
            if(count[i] > max){
                max = count[i];
                res = i;
            }
        }
        (max>(n/2))?(cout<<res<<"\n"):(cout<<"NO Majority Element\n");
    }
    return 0;
}
