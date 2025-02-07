#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int H, W;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
vector<vector<char>> grid;

struct dq_data
{
	int x;
	int y;
};

bool isInrange(int x, int y)
{
	return 0 <= x && x < H && 0 <= y && y < W;
}

int zeroOnebfs(int stx, int sty, int ndx, int ndy)
{
	vector<vector<int>> distance(H, vector<int>(W,INF)); 
	distance[stx][sty] = 0;
	deque<dq_data> dq;
	dq.push_back({stx,sty });

	while (!dq.empty())
	{
		dq_data here = dq.front(); dq.pop_front();

		if (here.x == ndx && here.y == ndy)
		{
			return distance[here.x][here.y];
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = here.x + dx[i];
			int ny = here.y + dy[i];

			if (!isInrange(nx, ny) || distance[nx][ny]<=distance[here.x][here.y] + (dy[i] != 1) || grid[nx][ny] == '#') continue;

			distance[nx][ny] = distance[here.x][here.y] + (dy[i] != 1);
			if (dy[i] == 1) dq.push_front({nx,ny});
			else dq.push_back({nx,ny});
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W;
	
	grid = vector<vector<char>>(H, vector<char>(W));
	
	int stx, sty, ndx, ndy;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'K') stx = i, sty = j;
			else if (grid[i][j] == '*') ndx = i, ndy = j;
		}
	}

	int ans = zeroOnebfs(stx, sty, ndx, ndy);
	cout << ans << '\n';
}