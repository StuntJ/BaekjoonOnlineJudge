#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<int> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    vector<vector<int>> adj(N+1);
    vector<int> dist(N+1,-1);

    while(M--){
        int a,b;
        cin>>a>>b;

        if(v[a]>v[b]) adj[b].emplace_back(a);
        else adj[a].emplace_back(b);
    }

    auto f = [&](auto &f, int here)->int{
        int &ret = dist[here];
        if(ret!=-1) return ret;
        ret = 1;
        for(auto next : adj[here]){
            ret = max(ret,f(f,next)+1);
        }
        return ret;
    };

    for(int i=1;i<=N;i++){
        cout<<f(f,i)<<'\n';
    }
}