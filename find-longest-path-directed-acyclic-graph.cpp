// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
#include <bits/stdc++.h>
using namespace std;

struct vec{
	int src,dst;
	int wt;
};

void topSort(int visited[], stack<int> &s, int v, vector<vector<vec> > &g){
	visited[v] = 1;
	for(int i=0;i<g[v].size();i++){
		if(!visited[g[v][i].dst])
			topSort(visited, s,g[v][i].dst,g);
	}
	s.push(v);
}

int main(){
	int v = 5, e = 7;
	vector<vector<vec> > g;
	g.resize(v+1);
	vec temp;
	for(int i=0;i<e;i++){
		cin>>temp.src>>temp.dst>>temp.wt;
		g[temp.src].push_back(temp);
	}
	int visited[100];
	int dist[100];
	stack<int> s;
	for(int i=0;i<=v;i++){
		visited[i] = 0;
		dist[i] = -INT_MAX;
	}
	dist[0] = 0;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			topSort(visited,s,i,g);
		}
	}
	vector<int> top;
	while(!s.empty()){
		top.push_back(s.top());
		s.pop();
	}

	for(int i=0;i<v;i++){
		for(int j=0;j<g[top[i]].size();j++){
			if(dist[g[top[i]][j].src] < dist[i] + g[top[i]][j].wt)
				dist[g[top[i]][j].src] = dist[i] + g[top[i]][j].wt;
		}
	}
	for(int i=0;i<=v;i++){
		cout << dist[i] << " ";
	}
	cout << endl;

	return 0; 
}