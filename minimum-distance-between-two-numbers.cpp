//http://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1
//minimum-distance-between-two-numbers
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    int arr[105];
    cin>>t;
    while(t--){
        int x,y;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>x>>y;
        int prev=-1, next=-1;
        int mindis = INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                prev = i;
            }
            if(arr[i]==y){
                next = i;
            }
            if(abs(next-prev) < mindis && prev != -1 && next != -1){
                mindis = abs(next-prev);
            }
        }
        (next != -1 && prev != -1)?(cout<<mindis<<"\n"):(cout<<"-1\n");
    }
    return 0;
}
