#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;

        vector<vector<int>> adj(N+1);
        while(M--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(N+1,-1);
        auto solve = [&](auto &solve, int here, int depth)->bool{
            visited[here] = depth;
            bool ret = true;
            for(auto next : adj[here]){
                if(visited[next]!=-1 && visited[next]%2==depth%2){
                    return false;
                }
                if(visited[next]==-1) 
                    ret &= solve(solve,next,depth+1); 
            }
            return ret;
        };

        bool ret = true;
        for(int i=1;i<=N;i++){
            if(visited[i]==-1)
                ret &=solve(solve,i,0);
        }
        cout<<(ret ? "YES\n" : "NO\n");
    }
}