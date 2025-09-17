#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;

        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<bool> visited(N+1);
    vector<int> color(N+1,-1);
    bool isOdd = false;
    auto dfs = [&](auto &dfs, int here)->void{
        visited[here] = true;
        for(auto next : adj[here]){
            if(!visited[next]){
                color[next] = !color[here];
                dfs(dfs,next);
            }
            else{
                if(color[next]==color[here]) isOdd = true;
            }
        }
    };

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            color[i] = 0;
            dfs(dfs,i);
        }
    }

    if(isOdd) cout<<0;
    else{
        int s = 0, t = 0;
        for(int i=1;i<=N;i++){
            if(color[i]) s++;
            else t++;
        }
        cout<<s*t*2;
    }
}