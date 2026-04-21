#include <bits/stdc++.h>

using namespace std;

const int LIM = 3e6+1;
const int INF = 1e9;

void solve() {
    int N;
    cin>>N;

    vector<int> dp(LIM,-1);
    vector<int> parent(LIM,-1);

    dp[N] = 0;
    for (int i=N-1;i>=1;i--) {
        dp[i] = INF;
        if (dp[i*3]!=-1) {
            if (dp[i]>dp[i*3]+1) {
                dp[i] = dp[i*3]+1;
                parent[i] = i*3;
            }
        }

        if (dp[i*2]!=-1) {
            if (dp[i]>dp[i*2]+1) {
                dp[i] = dp[i*2]+1;
                parent[i] = i*2;
            }
        }

        if (dp[i+1]!=-1) {
            if (dp[i]>dp[i+1]+1) {
                dp[i] = dp[i+1]+1;
                parent[i] = i+1;
            }
        }
    }

    cout<<dp[1]<<'\n';
    int bp = 1;
    vector<int> seq;
    seq.push_back(bp);
    while (parent[bp]!=-1) {
        bp = parent[bp];
        seq.push_back(bp);
    }

    for (int i=seq.size()-1; i>=0;i--) cout<<seq[i]<<' ';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}