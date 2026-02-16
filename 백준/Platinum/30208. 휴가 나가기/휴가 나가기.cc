#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

void solve() {
    int N, S;
    cin >> N >> S;
    
    vector<int> w(N), t(N);
    for(auto &i : w) cin >> i;
    for(auto &i : t) cin >> i;
    
    vector<vector<int>> adj(N);
    vector<int> roots;
    
    for(int i = 0; i < N; i++) {
        int p; cin >> p;
        if(p == 0) {
            roots.push_back(i); 
        } else {
            adj[p-1].push_back(i); 
        }
    }

    int cnt = roots.size();
    vector<vector<pair<int, int>>> bag(cnt);

    auto dfs = [&](auto &dfs, int here, int weight, int time, int group_idx) -> void {
        int cur_w = weight + w[here];
        int cur_t = time + t[here];
        
        bag[group_idx].push_back({cur_w, cur_t});
        
        for(auto nxt : adj[here]) {
            dfs(dfs, nxt, cur_w, cur_t, group_idx);
        }
    };

    for(int i = 0; i < cnt; i++) {
        dfs(dfs, roots[i], 0, 0, i);
    }

    vector<vector<int>> dp(cnt + 1, vector<int>(S + 1, INF));
    dp[0][0] = 0;

    for(int i = 0; i < cnt; i++) {
        for(int j = 0; j <= S; j++) {
            if(dp[i][j] == INF) continue;

            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

            for(auto &[wei, tim] : bag[i]) {
                int nxt_w = min(S, j + wei);
                dp[i+1][nxt_w] = min(dp[i+1][nxt_w], dp[i][j] + tim);
            }
        }
    }

    if(dp[cnt][S] >= INF) cout << -1;
    else cout << dp[cnt][S];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}