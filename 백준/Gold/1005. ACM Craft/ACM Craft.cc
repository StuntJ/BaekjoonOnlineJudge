#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int solve(int here, vector<vector<int>>& adjT, vector<int> &time, vector<int> &dp)
{
	if (!adjT[here].size()) return time[here];
	int& ret = dp[here];
	if (dp[here] != -1) return dp[here];

	ret = 0;
	for (int there = 0; there < adjT[here].size(); there++)
		ret = max(ret, solve(adjT[here][there], adjT, time, dp) + time[here]);

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		vector<int> time(N + 1);
		vector<vector<int>> adjT(N + 1);
		vector<int> dp(N + 1, -1);
		for (int i = 1; i < time.size(); i++)
			cin >> time[i];
		int start, end;
		for (int i = 0; i < K; i++)
		{
			cin >> start >> end;
			adjT[end].emplace_back(start);
		}
		int target;
		cin >> target;
		int ans = solve(target, adjT, time, dp);

		cout << ans << '\n';
	}
}
