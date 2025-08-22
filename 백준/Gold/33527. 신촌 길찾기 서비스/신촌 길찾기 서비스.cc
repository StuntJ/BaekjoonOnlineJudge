#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,X;
    cin>>N>>X;

    const ll INF = 1e15;
    vector<vector<ll>> bus(N,vector<ll>(5));
    vector<vector<ll>> adj(5*X+1,vector<ll>(5*X+1,INF));
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cin>>bus[i][j];
            bus[i][j] += X*j;
        }

        for(int j=0;j<5;j++){
            for(int k=j+1;k<5;k++){
                adj[bus[i][j]][bus[i][k]] = 1;
                adj[bus[i][k]][bus[i][j]] = 1;
            }
        }
    }

    for(int i=0;i<=5*X;i++) adj[i][i] = 0;

    for(int k=1;k<=5*X;k++)
        for(int i=1;i<=5*X;i++)
            for(int j=1;j<=5*X;j++)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
    
    int Q;
    cin>>Q;
    while(Q--){
        int u,v;
        cin>>u>>v;
        u--; v--;
        ll dist = INF;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                dist = min(dist,adj[bus[u][i]][bus[v][j]]);
            }
        }
        cout<<(dist==INF ? -1 : dist+1)<<'\n';    
    }
}