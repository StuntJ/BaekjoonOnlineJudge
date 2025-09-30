#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V+1,vector<int>(V+1,INF));

    for(int i=0;i<=V;i++) adj[i][i] = 0;

    for(int i=0;i<E;i++){
        int s,e,t;
        cin>>s>>e>>t;

        adj[s][e] = t;
    }

    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
        }
    }

    int minDist = INF;
    for(int i=1;i<=V;i++){
        for(int j=1;j<V;j++){
            if(i==j) continue;
            if(adj[i][j]+adj[j][i]<minDist) minDist = adj[i][j]+adj[j][i];
        }
    }

    if(minDist==INF) minDist = -1;
    cout<<minDist;
}