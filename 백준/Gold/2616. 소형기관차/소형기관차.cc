#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) cin >> v[i];

	vector<vector<int>> dp(N + 1, vector<int>(4, 0));
	int M;
	cin >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int ret = 0;
			if (i - M >= 0 && j > 0)
			{
				ret = dp[i - M][j - 1];
				for (int k = i - M + 1; k <= i; k++)
				{
					ret += v[k];
				}
			}
			dp[i][j] = max(ret, dp[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << dp[N][3];
}