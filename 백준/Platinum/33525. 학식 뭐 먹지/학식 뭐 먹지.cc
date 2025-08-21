#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> menu(M);
    for (auto &p : menu) cin >> p.first >> p.second;
    sort(menu.begin(), menu.end()); // 가격 오름차순

    const ll INF = 1e18;
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, INF));
    dp[0][0] = 0; // 0명 0개 메뉴는 비용 0

    for (int idx=0; idx<M; idx++) {
        ll A = menu[idx].first;
        ll B = menu[idx].second;

        // 뒤에서 앞으로 갱신 (같은 메뉴 중복 방지)
        for (int n=N; n>=0; n--) {
            for (int m=idx; m>=0; m--) {
                if (dp[n][m] == INF) continue;

                ll nnew = min((ll)N, n + B);
                // 이 메뉴 추가 사용
                dp[nnew][m+1] = min(dp[nnew][m+1],
                                    dp[n][m] + (nnew - n) * A);
            }
        }
    }

    ll ans = INF;
    for (int m=1; m<=M; m++) {
        if (dp[N][m] != INF) {
            ans = min(ans, dp[N][m] * m);
        }
    }
    cout << ans << "\n";
}