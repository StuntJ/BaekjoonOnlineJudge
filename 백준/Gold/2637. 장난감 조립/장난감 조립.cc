#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1), table(N+1,vector<int>(N+1));

    while(M--){
        int a,b,c;
        cin>>a>>b>>c;

        table[a][b] = c;
        adj[a].emplace_back(b);
    }

    vector<int> depth(N+1);
    auto dfs = [&](auto &dfs, int here)->int{
        int &ret = depth[here];
        if(ret!=0) return ret;
        ret = 1;

        for(auto next : adj[here]){
            ret = max(ret,dfs(dfs,next)+1);
        }
        return ret;
    };

    dfs(dfs,N);

    /* for(int i=1;i<=N;i++) cout<<depth[i]<<' ';
    cout<<'\n'; */

    vector<pair<int,int>> v(N); //depth, index
    for(int i=0;i<N;i++){
        v[i].first = depth[i+1];
        v[i].second = i+1;
    }

    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        if(v[i].first == 1) table[v[i].second][v[i].second] = 1;
        else{
            vector<int> temp(N+1);
            for(int j=1;j<=N;j++){
                int mul = table[v[i].second][j];
                if(mul>0){
                    for(int k=1;k<=N;k++){
                        temp[k] += table[j][k]*mul;
                    }
                }
            }
            table[v[i].second] = temp;
        }
    }

    for(int i=1;i<=N;i++){
        if(table[N][i]){
            cout<<i<<' '<<table[N][i]<<'\n';
        }
    }
}