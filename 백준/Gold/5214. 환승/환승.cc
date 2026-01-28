#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N,K,M;
    cin>>N>>K>>M;

    vector<vector<int>> adj(N+M+1);

    for(int i=1;i<=M;i++){
        for(int j=0;j<K;j++){
            int x;
            cin>>x;
            adj[N+i].push_back(x);
            adj[x].push_back(N+i);
        }
    }

    vector<int> dist(N+M+1,-1);
    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : adj[here]){
            if(dist[next]!=-1) continue;
            if(next>N){
                dist[next] = dist[here];
            }
            else dist[next] = dist[here] + 1;

            q.push(next);
        }
    }
    cout<<dist[N];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}