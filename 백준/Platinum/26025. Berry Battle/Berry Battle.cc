#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

const int INF = 1e9;

void solve() {
    int N;
    cin>>N;

    vector<vector<int>> adj(N+1);
    for (int i=0;i<N-1;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> prev(N+1,-1);
    vector<int> dist(N+1,INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (auto next : adj[here]) {
            if (dist[next]==INF) {
                dist[next] = dist[here]+1;
                q.push(next);
            }
        }
    }

    int st = -1;
    int mxDist = 0;
    for (int i=1;i<=N;i++) {
        if (mxDist<dist[i]) {
            mxDist = dist[i];
            st = i;
        }
    }

    dist = vector<int>(N+1,INF);
    dist[st] = 0;
    q.push(st);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (auto next : adj[here]) {
            if (dist[next]==INF) {
                prev[next] = here;
                dist[next] = dist[here]+1;
                q.push(next);
            }
        }
    }

    int diameter = 0;
    int target = -1;
    for (int i=1;i<=N;i++) {
        if (dist[i]>diameter) {
            diameter = dist[i];
            target = i;
        }
    }

    vector<int> path;
    vector<bool> chk(N+1);
    while (prev[target]!=-1) {
        chk[target] = true;
        path.push_back(target);
        target = prev[target];
    }
    chk[target] = true;
    path.push_back(target);

    if (path.size()<=3) {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    cout<<path[1]<<' '<<path[0]<<' ';
    for (int i=2;i<path.size();i++) {
        cout<<path[i]<<' ';
    }

    dist = vector<int>(N+1,INF);
    dist[path[0]] = 0;
    q.push(path[0]);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (auto next : adj[here]) {
            if (dist[next]==INF) {
                dist[next] = dist[here]+1;
                q.push(next);
            }
        }
    }

    vector<pair<int,int>> data;
    for (int i=1;i<=N;i++) {
        if (chk[i]) continue;
        data.push_back({dist[i],i});
    }

    sort(all(data));

    for (auto i : data) cout<<i.second<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) {
        solve();
    }
}