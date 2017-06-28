//http://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
#include<bits/stdc++.h>
using namespace std;
struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
int main(){
    int t,n;
    int arr[10005];
    cin>>t;
    while(t--){
        cin>>n;
        int x;
        // multiset <int> s;
        // for(int i=0;i<n;i++){
        //     cin>>x;
        //     s.insert(x);
        // }
        // multiset <int> :: iterator it;
        // for(it = s.begin();it!=s.end();it++){
        //     cout<<(*it)<<" ";
        // }
        // cout<<endl;
        map<int ,int> m;
        for(int i=0;i<n;i++){
            cin>>x;
            if(m.find(x) != m.end()){
                m[x]++;
            }else{
                m.insert(make_pair(x,1));
            }
        }
        map<int,int> :: iterator it;
        multimap<int,int> mm;
        vector<pair<int ,int> > v;
        for(it = m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
            mm.insert(make_pair(it->second,it->first));
            v.push_back(make_pair(it->second,it->first));
        }
        sort(v.begin(),v.end());
        vector<int> vec;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
                //cout<<v[i].second<<" ";
                vec.push_back(v[i].second);
            }
        }
        for(int i=vec.size() - 1;i>=0;i--){
            cout<<vec[i]<<" ";
        }
        // multimap <int,int> :: reverse_iterator mit;
        // for(mit = mm.rbegin();mit!=mm.rend();mit++){
        //     for(int i=0;i<mit->first;i++){
        //         cout<<mit->second<<" ";
        //     }
        // }
        cout<<endl;
    }
    return 0;
}
