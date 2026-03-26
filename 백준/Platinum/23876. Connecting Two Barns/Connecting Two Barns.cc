#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;

struct disjoint_set{
    vector<int> parent,rank;
    disjoint_set(int n) : parent(n),rank(n,1){
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v){
        u = find(u); v = find(v);
        if(u==v) return false;
        if(rank[u]>rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
        return true;
    }
};

void solve(){
    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    disjoint_set d_set(N+1);
    vector<bool> visited(N+1);

    function<void(int)> dfs = [&](int here){
        visited[here] = true;

        for(auto next : adj[here]){
            if(!visited[next]){
                d_set.merge(here,next);
                dfs(next);
            }
        }
    };

    for(int here=1;here<=N;here++){
        if(!visited[here]) dfs(here);
    }

    vector<ll> distF(N+1,1e18), distB(N+1,1e18);
    
    vector<int> F,B;

    if(d_set.find(1)==d_set.find(N)){
        cout<<0<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        if(d_set.find(i)==d_set.find(1)) F.push_back(i);
        if(d_set.find(i)==d_set.find(N)) B.push_back(i); 
    }

    function<ll(vector<int>&, int)> func = [&](vector<int> &vec, ll node){
        auto it = lower_bound(vec.begin(),vec.end(),node);
        ll ans = (node - *it)*(node - *it);
        if(it!=vec.begin()){
            it--;
            ans = min(ans,(node - *it)*(node - *it));
        }
        return ans;
    };

    for(int i=1;i<=N;i++){
        if(int k = d_set.find(i); k!=d_set.find(1)){
            distF[k] = min(distF[k],func(F,i));
        }
        if(int k = d_set.find(i); k!=d_set.find(N)){
            distB[k] = min(distB[k],func(B,i));
        }
    }

    vector<bool> chk(N+1);

    ll totAns = distF[d_set.find(N)];
    for(int i=1;i<=N;i++){
        if(d_set.find(i)!=d_set.find(1) && d_set.find(i)!=d_set.find(N) && !chk[d_set.find(i)]){
            chk[d_set.find(i)] = true;
            totAns = min(distF[d_set.find(i)]+distB[d_set.find(i)],totAns);
        }
    }

    cout<<totAns<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin>>t;
    while(t--){
        solve();
    }
}