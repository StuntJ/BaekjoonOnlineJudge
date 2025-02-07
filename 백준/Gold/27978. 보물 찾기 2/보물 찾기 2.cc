#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int H, W;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
vector<vector<char>> grid;

struct pq_data
{
	int dist;
	int x;
	int y;

	bool operator < (const pq_data& rhs) const
	{
		return dist > rhs.dist;
	}
};

bool isInrange(int x, int y)
{
	return 0 <= x && x < H && 0 <= y && y < W;
}

vector<vector<int>> dijkstra(int stx, int sty)
{
	vector<vector<int>> dist(H, vector<int>(W, INF));
	dist[stx][sty] = 0;
	priority_queue<pq_data> pq;
	pq.push({ 0,stx,sty });
	
	while (!pq.empty())
	{
		pq_data here = pq.top(); pq.pop();

		if (here.dist > dist[here.x][here.y]) continue;

		for (int i = 0; i < 8; i++)
		{
			int nx = here.x + dx[i];
			int ny = here.y + dy[i];
			int nextDist = here.dist + (dy[i] != 1);

			if (!isInrange(nx, ny) || grid[nx][ny] == '#') continue;

			if (dist[nx][ny] > nextDist)
			{
				dist[nx][ny] = nextDist;
				pq.push({ nextDist,nx,ny });
			}
		}
	}
	return dist;
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

	vector<vector<int>> dist = dijkstra(stx, sty);

	if (dist[ndx][ndy] >= INF) cout << -1 << '\n';
	else cout << dist[ndx][ndy] << '\n';
}