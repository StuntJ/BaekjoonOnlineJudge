#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M, T;

int dfs(vector<vector<int>>& board, int x, int y, const int start)
{
	board[x][y] = 0;
	int ret = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && board[nx][(ny + M) % M] == start)
			ret += dfs(board, nx, (ny + M) % M, start);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;
	vector<vector<int>> board(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	while (T--)
	{
		int x, d, k;
		cin >> x >> d >> k;

		for (int i = x - 1; i < N; i += x)
		{
			if (d) rotate(board[i].begin(), board[i].begin() + k, board[i].end());
			else rotate(board[i].begin(), board[i].end() - k, board[i].end());
		}

		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] != 0)
				{
					int bp = board[i][j];
					if (dfs(board, i, j, board[i][j]) > 1)
						flag = true;
					else
						board[i][j] = bp;
				}
			}
		}

		

		if (!flag)
		{
			int sum = 0;
			int cnt = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					sum += board[i][j];
					if (board[i][j] != 0) cnt++;
				}
			}
			if (cnt == 0) continue;
			/*cout << sum << ' ' << cnt << '\n';*/
			double res = sum / (double)cnt;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if(board[i][j]!=0)
					{
						if (res < board[i][j]) board[i][j]--;
						else if (res > board[i][j]) board[i][j]++;
					}
				}
			}
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}*/
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			sum += board[i][j];

	cout << sum << '\n';
}