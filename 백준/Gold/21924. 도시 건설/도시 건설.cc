#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int st;
    int nd;
    ll w;

    bool operator < (const edge &rhs) const {
        return w>rhs.w;
    }
};

struct disjoint_set {
    vector<int> parent,rank;
    disjoint_set(int n) : parent(n),rank(n,1) {
        for (int i=0;i<n;i++) parent[i] = i;
    }

    int find(int v) {
        if (parent[v]==v) return v;
        return parent[v] = find(parent[v]);
    }

    bool merge(int u,int v) {
        u = find(u), v=find(v);
        if (u==v) return false;
        if (rank[u]>rank[v]) swap(u,v);
        parent[u] = v;
        rank[v] += rank[u];
        return true;
    }
};

void solve() {
    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1);
    priority_queue<edge> pq;
    disjoint_set d_set(N+1);
    for (int i=0;i<M;i++) {
        int a,b;
        ll w;
        cin>>a>>b>>w;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        pq.push({a,b,w});
    }

    int cnt = 0;
    vector<bool> visited(N+1);

    function<void(int)> dfs = [&](int here) {
        visited[here] = true;

        for (auto next : adj[here]) {
            if (!visited[next]) dfs(next);
        }
    };

    for (int i=1;i<=N;i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
        if (cnt>1) {
            cout<<-1;
            return;
        }
    }

    ll totWeight = 0;
    ll weight = 0;
    while (!pq.empty()) {
        edge p = pq.top();
        pq.pop();
        totWeight += p.w;

        if (d_set.merge(p.st,p.nd)) {
            weight += p.w;
        }
    }

    cout<<totWeight-weight;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}