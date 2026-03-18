#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    vector<vector<int>> adj(N+1);
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> cal(2);
    vector<int> num(2);

    function<void(int,int,int)> dfs = [&](int here, int parent, int cnt = 0){
        cal[cnt%2] += v[here];
        num[cnt%2]++;

        for(auto next : adj[here]){
            if(next==parent) continue;
            dfs(next,here,cnt+1);
        }
    };

    dfs(1,-1,0);
    for(int i=0;i<2;i++) cal[i]%=12;
    if(cal[0]==cal[1]) cout<<num[0]+num[1];
    else if((cal[0]+1)%12==cal[1]) cout<<num[1];
    else if(cal[0]==(cal[1]+1)%12) cout<<num[0];
    else cout<<0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}