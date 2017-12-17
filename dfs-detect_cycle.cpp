// dfs and detect cycle
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &g, vector<int> &vis, int v){
	vis[v] = true;
	cout << v << " ";
	for(int i=g[v].begin();i!=g[v].end();i++){
		if(!vis[v]){
			dfs(g,vis,i);
		}
	}
}

int main(){
	int V,e, u, v;
	cin>>V;
	vector<vector<int> > g;
	g.resize(V+1);
	for(int i=0;i<e;i++){
		cin>>u>>v;
		g[u].push_back(v);
	}
	vector<int> visited;
	visited.resize(V+1);
	for(int i=0;i<V+1;i++) visited = 0;
	dfs(g, visited, V);
	return 0;
}