#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

void solve() {
    int N;
    cin>>N;

    vector<vector<int>> adj(N,vector<int>(N));

    for (auto &i : adj) for (auto &j : i) cin>>j;

    for (int i=0;i<N;i++) for (int j=0;j<N;j++) if (i!=j && adj[i][j]==0) adj[i][j] = INF;

    int size = (1<<(N-1));
    vector<vector<int>> dp(N,vector<int>(size,INF)); //v_j->v_x->v_x->v_x->v_1
    vector<vector<int>> P(N,vector<int>(size,-1));

    for (int i=1;i<N;i++) {
        dp[i][0] = adj[i][0]; //v_j->v_1 설정하고 가운데 끼워 넣는거
    }

    for (int k=1;k<=N-2;k++) {
        for (int stat = 1; stat<size; stat++) {
            int cnt = __builtin_popcount(stat);
            if (cnt==k) {
                for (int i=1;i<N;i++) {
                    if (!(stat&(1<<(i-1)))) {
                        for (int j=1;j<N;j++) {
                            if (stat&(1<<(j-1))) {
                                int prev = stat&~(1<<(j-1));
                                if (dp[i][stat]>dp[j][prev]+adj[i][j]) {
                                    dp[i][stat] = dp[j][prev]+adj[i][j];
                                    P[i][stat] = j; //i, stat일때 j로 전이하는게 이득
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i=1;i<N;i++) { //v_i->...->v_0 을 이용하여 v_0->v_i->...v_0
        int full = size-1;
        int prev = full & ~(1<<(i-1));

        if (dp[0][full]>dp[i][prev]+adj[0][i]) {
            dp[0][full] = dp[i][prev]+adj[0][i];
            P[0][full] = i;
        }
    }

    cout<<dp[0][size-1]<<'\n';
    
    // function<void(int,int)> f = [&](int here, int stat) {
    //     cout<<here<<"->";
    //     int next = P[here][stat];
    //     if (next!=-1)
    //         f(next,stat&~(1<<(next-1)));
    // };
    //
    // f(0,size-1);
    // cout<<0<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}