#include <bits/stdc++.h>
using namespace  std;
 
typedef long long ll;
typedef array<ll, 2> pll;
#define all(x) (x).begin(), (x).end()
 
bool IsBipartite(vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &color, int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;
    color[root] = false;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
 
        for (auto next : adj[here]) {
            if (visited[next]) {
                if (color[here]==color[next]) return false;
                else continue;
            }
            q.push(next);
            color[next] = !color[here];
            visited[next] = true;
        }
    }
    return true;
}
 
ll fpow(ll n, ll p, ll mod) {
    if (p==0) return 1;
    ll temp = fpow(n,p/2,mod);
    ll ret = temp*temp%mod;
    if (p&1) return ret*n%mod;
    return ret;
}
 
void solve() {
    ll n,m,p;
    cin>>n>>m>>p;
 
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1);
    vector<bool> color(n+1);
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int cnt = 0;
    bool flag = false;
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        if (IsBipartite(adj,visited,color,i)) {
            cnt++;
        }
        else {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout<<"impossible";
    }
    else {
        cout<<(fpow(2LL,cnt-1,p)+1)%p;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; // cin >> t;
    while (t--) {
        solve();
    }
}