//
//unique-substrings
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int t,k;
    cin>>t;
    while(t--){
        string s;
        set<string> st;
        cin>>s>>k;
        //cout<<s<<" "<<k;
        if(s.length() % k !=0) cout<<"-1\n";
        else{
            for(int i=0;i<s.length();i+=k){
                if(i+k <= s.length()){
                    string str = s.substr(i,k);
                    st.insert(str);
                }
            }
            set<string> :: iterator it;
            int sum = 0;
            for(it=st.begin();it!=st.end();it++){
                //cout<<(*it)<<" ";
                long ans = strtol((*it).c_str(),NULL,2);
                sum += ans;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
