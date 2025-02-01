#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;
vector<vector<char>> grid;
vector<vector<vector<int>>> dp;
string str;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


bool isInrange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < M;
}

int dfs(int x, int y, int depth)
{
	if (depth == str.size()) return 1;
	int& ret = dp[x][y][depth];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x;
		int ny = y;
		for (int j = 0; j < K; j++)
		{
			nx += dx[i];
			ny += dy[i];
			
			if (!isInrange(nx, ny)) break;
			if (grid[nx][ny] == str[depth])
				ret += dfs(nx, ny, depth + 1);
		}
	}
	return ret;
}

int dfs_All()
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == str[0])
			{
				total += dfs(i, j, 1);
			}
		}
	}
	return total;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;

	grid = vector<vector<char>>(N, vector<char>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];

	cin >> str;

	dp = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(str.size()+1, -1)));
	cout << dfs_All();
}