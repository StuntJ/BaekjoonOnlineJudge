#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct q_data
{
	int x;
	int y;
	int t;
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;

bool isInrange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;

	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	queue<q_data> q;
	vector<vector<int>> visited(N, vector<int>(M, INF));
	q.push({ 0,0,0 });
	visited[0][0] = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().t;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isInrange(nx, ny))
			{
				int nt = t;
				//cout << nx << ' ' << ny << ' ' << nt << '\n';
				if (board[nx][ny] == '1') nt++;
				if (nt < visited[nx][ny])
				{
					q.push({ nx,ny,nt });
					visited[nx][ny] = nt;
				}
			}
		}
	}
	cout << visited[N - 1][M - 1];
}