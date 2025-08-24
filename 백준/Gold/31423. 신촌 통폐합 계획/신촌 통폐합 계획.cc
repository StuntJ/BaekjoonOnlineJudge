#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<string> v(N);
    for(auto &i : v) cin>>i;

    vector<bool> inDegree(N);
    vector<vector<int>> adj(N);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        
        adj[a].emplace_back(b);
        inDegree[b] = true;
    }

    int start = 0;
    for(int i=0;i<N;i++) if(!inDegree[i]) start = i;

    string str;
    vector<bool> visited(N);

    auto dfs = [&](auto &dfs, int here)->void{
        visited[here] = true;
        str+=v[here];

        for(auto next : adj[here]){
            if(!visited[next]) dfs(dfs,next);
        }
    };

    dfs(dfs,start);
    cout<<str;
}