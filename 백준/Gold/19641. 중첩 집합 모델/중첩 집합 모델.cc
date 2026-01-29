#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin>>N;

    vector<vector<int>> adj(N+1);
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        while(true){
            int n;
            cin>>n;
            if(n==-1) break;
            adj[x].emplace_back(n);
        }
        sort(adj[x].begin(),adj[x].end());
    }

    vector<pair<int,int>> v(N+1);
    int cnt = 1;
    auto f = [&](auto &f, int here, int parent = -1)->void{
        v[here].first = cnt++;
        for(auto next : adj[here]){
            if(next==parent) continue;
            f(f,next,here);
        }
        v[here].second = cnt++;
    };

    int r;
    cin>>r;
    f(f,r);
    for(int i=1;i<=N;i++) cout<<i<<' '<<v[i].first<<' '<<v[i].second<<'\n';
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