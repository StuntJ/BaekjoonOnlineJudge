#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	string str1, str2;
	cin >> str1 >> str2;

	str1.insert(str1.begin(), '@');
	str2.insert(str2.begin(), '@');
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) dp[i][0] = i;
	for (int i = 1; i <= M; i++) dp[0][i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (str1[i] == str2[j] || (str1[i] == 'i' && (str2[j] == 'j' || str2[j] == 'l')) || (str1[i] == 'v' && str2[j] == 'w')) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
			}
		}
	}

	cout << dp[N][M];
}