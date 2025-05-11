#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> g(N, vector<char>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];

	vector<vector<bool>> visit(N, vector<bool>(M));
	vector<vector<int>> dp(N, vector<int>(M,-1));
	int ans = 0;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	auto solve = [&](auto & solve, int x, int y)->int
	{
		int val = g[x][y] - '0';
		int& ret = dp[x][y];
		if (ret != -1) return ret;
		if (g[x][y] == 'H') return 0;
		visit[x][y] = true;
		ret = 0;
		
		int add = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + val * dx[i];
			int ny = y + val * dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (visit[nx][ny])
				{
					visit[x][y] = false;
					ans = -1;
					return 0;
				}
				else
				{
					add = max(add, 1 + solve(solve, nx, ny));
				}
			}
			else
			{
				add = max(add, 1);
			}
		}
		ret += add;
		visit[x][y] = false;
		return ret;
	};
	int k = solve(solve, 0, 0);
	if (ans == -1) cout << -1;
	else cout << k;
}