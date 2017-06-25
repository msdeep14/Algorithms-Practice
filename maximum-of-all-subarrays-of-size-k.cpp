//http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
//maximum-of-all-subarrays-of-size-k
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        int arr[105];
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //use deque
        deque<int> q(k);
        int i;
        for(i=0;i<k;i++){
            while(!q.empty() && arr[i] >= arr[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        for(;i<n;i++){
            cout<<arr[q.front()]<<" ";
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() && arr[i]>=arr[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        cout<<arr[q.front()];

        /*
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(arr[i]);
        }
        multiset<int>:: reverse_iterator rt;
        rt = s.rbegin();
        cout<<(*rt)<<" ";
        int j=0;
        for(int i=k;i<n;i++){
            multiset<int> :: iterator it;
            it = s.find(arr[j]);
            if(it != s.end()){
                s.erase(it);
            }
            s.insert(arr[i]);
            j++;
            rt = s.rbegin();
            cout<<(*rt)<<" ";
        }*/
        cout<<endl;
    }
    return 0;
}
