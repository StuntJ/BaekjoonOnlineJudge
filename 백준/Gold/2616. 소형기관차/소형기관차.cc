#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N + 1);
	vector<int> pSum(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
		pSum[i] = pSum[i - 1] + v[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(4, 0));
	int M;
	cin >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i - M >= 0 && j > 0) dp[i][j] = dp[i - M][j - 1] + pSum[i] - pSum[i - M];
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << dp[N][3];
}