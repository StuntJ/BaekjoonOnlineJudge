#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[11][11][11];
int s0[201];
bool dp[201][11][11];

bool check(int first, int second) {
    // 매번 DP 테이블 초기화
    memset(dp, 0, sizeof(dp));
    
    // 초기 상태: s-1의 1번 칸이 first, 2번 칸이 second일 때
    dp[2][first][second] = true;

    for (int i = 2; i < n; i++) {
        for (int cur = 1; cur <= m; cur++) {
            for (int nxt = 1; nxt <= m; nxt++) {
                if (!dp[i][cur][nxt]) continue;
                
                // s-1의 i+1번째 칸에 올 수 있는 후보 val을 찾음
                for (int val = 1; val <= m; val++) {
                    // s0[i] = f(s-1[i-1], s-1[i], s-1[i+1])
                    if (f[cur][nxt][val] == s0[i]) {
                        dp[i + 1][nxt][val] = true;
                    }
                }
            }
        }
    }

    // 마지막 연결 확인 (원형 구조)
    // dp[n][cur][last]가 참이라면, s-1[n-1]=cur, s-1[n]=last 인 상태임
    for (int cur = 1; cur <= m; cur++) {
        for (int last = 1; last <= m; last++) {
            if (dp[n][cur][last]) {
                // 마지막 조건 2개 체크:
                // s0[n] = f(s-1[n-1], s-1[n], s-1[1])
                // s0[1] = f(s-1[n], s-1[1], s-1[2])
                if (f[cur][last][first] == s0[n] && f[last][first][second] == s0[1]) {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve() {
    if (!(cin >> n >> m)) return;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                cin >> f[i][j][k];

    for (int i = 1; i <= n; i++) cin >> s0[i];

    // s-1의 첫 두 칸(1번, 2번)을 모든 경우의 수(M*M)로 시도
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(i, j)) {
                cout << "yes" << endl;
                return;
            }
        }
    }
    cout << "no" << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1; //cin>>t;
    while(t--){
        solve();
    }
}