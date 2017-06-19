//geeksforgeeks
//Find four elements a, b, c and d in an array such that a+b = c+d
#include<iostream>
#include<map>
using namespace std;
int main(){
	map<int ,pair<int, int> > m;
	int t,n;
	int arr[105];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		int flag=0;
		for(int i=0;i<n && flag==0;i++){
			for(int j=i+1;j<n && flag==0;j++){
				int sum = arr[i] + arr[j];
				//map<int, pair<int,int> > :: iterator it = m.find(sum);
				if(m.find(sum) == m.end()){
					m[sum] = make_pair(i,j);
				}else{
					flag = 1;
					break;
				}
			}
		}
		(flag==1)?(cout<<"1\n"):(cout<<"0\n");
		m.clear();
		/*
			if you forget to clear the map at end, you will wonder why im getting wrong answer :P
		*/
	}
	return 0;
}