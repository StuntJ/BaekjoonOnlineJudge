#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[11][11][11];
int s0[201];
bool dp[201][11][11];

bool check(int first, int second){
    memset(dp, 0, sizeof(dp));
    dp[2][first][second] = true;

    for (int i = 2; i < n; i++){
        for (int cur = 1; cur <= m; cur++){
            for (int nxt = 1; nxt <= m; nxt++){
                if (!dp[i][cur][nxt]) continue;
                for (int val = 1; val <= m; val++){
                    if (f[cur][nxt][val] == s0[i]){
                        dp[i + 1][nxt][val] = true;
                    }
                }
            }
        }
    }

    for (int cur = 1; cur <= m; cur++){
        for (int last = 1; last <= m; last++){
            if (dp[n][cur][last]){
                if (f[cur][last][first] == s0[n] && f[last][first][second] == s0[1]){
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                cin >> f[i][j][k];

    for (int i = 1; i <= n; i++) cin >> s0[i];

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if (check(i, j)) {
                cout << "yes" << '\n';
                return;
            }
        }
    }
    cout << "no" << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1; //cin>>t;
    while(t--){
        solve();
    }
}