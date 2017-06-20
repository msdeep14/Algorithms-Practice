//
//print-first-letter-of-every-word-in-the-string
#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        int mark = 0;
        getline(cin,s);
        if(s[0] != ' ') cout<<s[0];
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                mark = 1;
            }else if(s[i] != ' ' && mark == 1){
                cout<<s[i];
                mark = 0;
            }
        }
        cout<<endl;
    }
    return 0;
}
