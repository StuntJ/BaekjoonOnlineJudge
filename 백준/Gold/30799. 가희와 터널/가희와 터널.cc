#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(8));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 7; j++) {
			if (j < 7) dp[i][j] = 6 * dp[i - 1][j] + (j>0 ? dp[i - 1][j - 1] : 0);
			else dp[i][j] = 7 * dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[N][7];
}