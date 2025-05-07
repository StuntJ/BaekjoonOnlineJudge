#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		
		vector<vector<int>> dp(4, vector<int>(N+1, -1));

		auto solve = [&](auto& solve, int here, int n)->int
		{
			if (n == N) return 1;
			if (n > N) return 0;
			int& ret = dp[here][n];
			if (ret != -1) return ret;
			ret = 0;
			for (int i = here; i <= 3; i++)
			{
				ret += solve(solve, i, n + i);
			}
			return ret;
		};
		cout << solve(solve, 1, 0) << '\n';
	}
}