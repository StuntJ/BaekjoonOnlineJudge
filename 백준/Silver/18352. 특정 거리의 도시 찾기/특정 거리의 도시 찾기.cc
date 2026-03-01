#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K,X;
    cin>>N>>M>>K>>X;

    vector<vector<int>> adj(N+1);

    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
    }

    const int INF = 1e9;
    vector<int> dist(N+1,INF);

    dist[X] = 0;
    queue<int> q;
    q.push(X);

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : adj[here]){
            if(dist[next]==INF){
                dist[next] = dist[here]+1;
                q.push(next);
            }
        }
    }

    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(dist[i]==K){
            ans.push_back(i);
        }
    }

    if(ans.empty()) cout<<-1;
    else for(auto i : ans) cout<<i<< '\n';
    
}