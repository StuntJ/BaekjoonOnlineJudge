#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> g(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)	
			cin >> g[i][j];
		
	vector<int> dp(M);
	dp[0] = g[0][0];
	for (int i = 1; i < M; i++) dp[i] = dp[i - 1] + g[0][i];

	for (int i = 1; i < N; i++)
	{
		
		for (int j = 0; j < M; j++) dp[j] += g[i][j];
		vector<int> cdp = dp;
		int cur = dp[0];
		for (int j = 1; j < M; j++)
		{
			if (cur+g[i][j]>dp[j]) cur = dp[j] = cur + g[i][j];
			else cur = dp[j];
		}

		cur = cdp[M - 1];
		for (int j = M - 2; j >= 0; j--)
		{
			if (cur+g[i][j]>cdp[j]) cur = cdp[j] = cur + g[i][j];
			else cur = cdp[j];
		}
		

		for (int j = 0; j < M; j++)
			dp[j] = max(dp[j], cdp[j]);
	}
	cout << dp[M - 1];
}