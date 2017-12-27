// https://www.geeksforgeeks.org/topological-sorting/
#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int> > &g, vector<int> &visited, int v, stack<int> &s){
	visited[v] = 1;
	for(int i=0;i<g[v].size();i++){
		if(!visited[g[v][i]])
			topoSort(g,visited,g[v][i],s);
	}
	s.push(v);
}

int main(){
	vector<vector <int> > g;
	int V = 6;
	vector<int > visited;
	g.resize(V+1);
	visited.resize(V+1);
	for(int i=0;i<V;i++)
		visited[i] = 0;
	g[5].push_back(0);
	g[5].push_back(2);
	g[4].push_back(0);
	g[4].push_back(1);
	g[2].push_back(3);
	g[3].push_back(1);
	stack<int > s;
	for(int i=0;i<V;i++){
		if(!visited[i])
			topoSort(g,visited,i,s);
	}
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}