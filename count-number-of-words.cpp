//
//count-number-of-words
#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        //cout<<s<<endl;
        //cout<<"len::"<<s.length()<<endl;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='\\' || s[i]==' ') count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
