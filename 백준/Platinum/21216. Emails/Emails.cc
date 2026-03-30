#include  <bits/stdc++.h>
#define all(x) (v).begin(),(v).end()

using namespace std;
typedef long long ll;

void solve() {
    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1);
    for (int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int st = 1;
    vector<int> dist(N+1,-1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (auto next : adj[here]) {
            if (dist[next]==-1) {
                q.push(next);
                dist[next] = dist[here]+1;
            }
        }
    }

    int distM = 0;
    int newD = -1;
    for (int i=1;i<=N;i++) {
        if (distM<dist[i]) {
            distM = dist[i];
            newD = i;
        }
        if (dist[i]==-1) {
            cout<<-1;
            return;
        }
    }

    dist = vector<int>(N+1,-1);
    dist[newD] = 0;
    q.push(newD);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (auto next : adj[here]) {
            if (dist[next]==-1) {
                q.push(next);
                dist[next] = dist[here]+1;
            }
        }
    }

    int ans = -1;
    for (int i=1;i<=N;i++) {
        if (dist[i]>ans) ans = dist[i];
    }

    ans--;
    int cnt = 0;
    while (ans) {
        cnt++;
        ans>>=1;
    }
    cout<<cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) {
        solve();
    }
}