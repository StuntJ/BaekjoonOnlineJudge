#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> board;

struct disjoint_set
{
	vector<int> parent, rank;
	disjoint_set(int n)
	{
		parent.resize(n + 1);
		rank.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	bool merge(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (a > b) swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
		return true;
	}
};

struct pq_data
{
	int s;
	int e;
	int cost;

	bool operator < (const pq_data& rhs) const
	{
		return cost > rhs.cost;
	}
};

bool isInrange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < M;
}

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, vector<vector<bool>>& visited, int vertexCounter)
{
	visited[x][y] = true;
	board[x][y] = vertexCounter;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInrange(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1)
			dfs(nx, ny, visited, vertexCounter);
	}
}

int vertexCounter = 1;
void dfs_all()
{
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j] && board[i][j] == 1)
				dfs(i, j, visited, vertexCounter++);
}

int kruskal(priority_queue<pq_data>& pq, disjoint_set& d_set)
{
	int total = 0;
	while (!pq.empty())
	{
		pq_data ret = pq.top();
		pq.pop();
		if (d_set.merge(ret.s, ret.e))
			total += ret.cost;
	}
	return total;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	dfs_all();

	priority_queue<pq_data> pq;
	disjoint_set d_set(vertexCounter);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx, ny;
					nx = i, ny = j;
					int cnt = 0;
					while (true)
					{
						nx += dx[k];
						ny += dy[k];
						if (isInrange(nx, ny) && board[nx][ny] == 0) cnt++;
						else
						{
							if (!isInrange(nx, ny)) break;
							if (board[i][j] >= board[nx][ny]) break;
							if (cnt < 2) break;
							pq.push({ board[i][j],board[nx][ny],cnt });
							break;
						}
					}
				}
			}
		}
	}

	int ans = kruskal(pq, d_set);
	int num = d_set.find(1);
	bool flag = false;
	for (int i = 2; i < vertexCounter; i++)
	{
		if (d_set.find(i) != num)
		{
			flag = true;
			break;
		}
	}

	if (flag) cout << -1;
	else cout << ans;
}