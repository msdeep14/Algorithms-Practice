//
//k-anagrams-1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		vector <string> vec;
		vector<int> countarr;
		cin>>n;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			vec.push_back(s);
		}
		
		map<string,int> m;
		for(int i=0;i<vec.size();i++){
			sort(vec[i].begin(),vec[i].end());
			if(m.find(vec[i]) == m.end()){
				m[vec[i]] = 1;
			}else{
				int x = m[vec[i]];
				m[vec[i]] = x+1;
			}
		}
		map<string,int> :: iterator it;
		for(it = m.begin();it!=m.end();it++){
			countarr.push_back(it->second);
		}
		sort(countarr.begin(),countarr.end());		
		 for(int i=0;i<countarr.size();i++){
		 	cout<<countarr[i]<<" ";
		 }
		 countarr.clear();
		 m.clear();
		 vec.clear();
		 cout<<endl;
	}
	return 0;
}