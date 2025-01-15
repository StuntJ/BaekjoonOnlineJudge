#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> A(N), B(N);

	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<vector<int>> dp(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		if (A[0] > B[i])
			dp[0][i] = 2;
		else if (A[0] == B[i])
			dp[0][i] = 1;
		if (i > 0) dp[0][i] = max(dp[0][i],dp[0][i - 1]);
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (A[i] > B[j])
			{
				if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
				else dp[i][j] = max(dp[i][j], 2);
			}
			else if (A[i] == B[j])
			{
				if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				else dp[i][j] = max(dp[i][j], 1);
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//		cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}
	cout << dp[N - 1][N - 1];
}