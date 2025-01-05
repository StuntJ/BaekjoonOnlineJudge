#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

struct q_data
{
	int x;
	int y;
	int t;
};

int M, N, V;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool isInrange(int x, int y)
{
	return 0 <= x && x < M && 0 <= y && y < N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> V;
	vector<vector<int>> board(M, vector<int>(N));
	vector<vector<int>> arrival(M, vector<int>(N, INF));
	int jx, jy;
	cin >> jx >> jy;
	jx--; jy--;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < V; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		x--; y--;
		arrival[x][y] = 0;
		queue<q_data> q;
		vector<vector<bool>> visited(M, vector<bool>(N, false));
		q.push({ x,y,t });
		visited[x][y] = true;
		
		while (!q.empty())
		{
			int hx = q.front().x;
			int hy = q.front().y;
			int ht = q.front().t;
			q.pop();
			arrival[hx][hy] = min(arrival[hx][hy], ht);

			for (int i = 0; i < 4; i++)
			{
				int nx = hx + dx[i];
				int ny = hy + dy[i];
				if (isInrange(nx, ny) && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push({ nx,ny,ht + 1 });
				}
			}
		}
	}
	queue<q_data> q;
	vector<vector<bool>> visited(M, vector<bool>(N, false));
	q.push({ jx,jy,1 });
	visited[jx][jy] = true;
	int Mheight = 0;
	int time = 0;
	while (!q.empty())
	{
		int hx = q.front().x;
		int hy = q.front().y;
		int ht = q.front().t;
		q.pop();
		if (Mheight < board[hx][hy])
		{
			Mheight = board[hx][hy];
			time = ht;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (isInrange(nx, ny) && !visited[nx][ny] && arrival[nx][ny] > ht)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny,ht + 1 });
			}
		}
	}
	cout << Mheight << ' ' << time-1 << '\n';
	/*for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arrival[i][j] << ' ';
		cout << '\n';
	}*/
}