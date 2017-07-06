//graph bfs
#include <bits/stdc++.h>
using namespace std;
struct graph{
    int wt;
    int src,dst;
};
void bfs(vector<vector <graph > > &vec,int n, int start, int end){
    set<int> s;
    queue<int> q;
    s.insert(start);
    q.push(start);
    cout<<start<<" ";
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=0;i<vec[current].size();i++){
            if(s.find(vec[current][i]) == s.end()){
                s.insert(vec[current][i]);
                q.push(vec[current][i]);
                cout<<vec[current][i]<<" ";
            }
        }
        q.pop();
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e,u,v,data,start,end;
        vector <vector<graph> > vec;
        cin>>n>>e;
        vec.resize(n+1);
        for(int i=0;i<e;i++){
            graph g;
            cin>>u>>v>>data;
            g.src = u;
            g.dst = v;
            g.wt = data;
            vec[i].push_back(g);
        }
        cin>>start>>end;
        bfs(vec,n,start,end);
    }
    return 0;
}
