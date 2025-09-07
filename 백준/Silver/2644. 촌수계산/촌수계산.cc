#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int st,nd;
    cin>>st>>nd;

    int M;
    cin>>M;

    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    const int INF = 1e9;
    vector<int> dist(N+1,INF);
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : adj[here]){
            if(dist[next]!=INF) continue;
            dist[next] = dist[here] + 1;
            q.push(next); 
        }   
    }

    cout<<(dist[nd]==INF ? -1 : dist[nd]);
}