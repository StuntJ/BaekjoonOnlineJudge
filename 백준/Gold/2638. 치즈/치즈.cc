#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vvi grid(N, vi(M));
	vpi Q;
	vb inQ;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
			{
				Q.push_back({ i,j });
				inQ.push_back(true);
			}
		}
	}

	auto isInrange = [&](int x, int y)
		{
			return 0 <= x && x < N && 0 <= y && y < M;
		};

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	auto dfs = [&](auto& dfs, int x, int y) -> void
		{
			grid[x][y] = -1;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (!isInrange(nx, ny) || grid[nx][ny] != 0) continue;
				dfs(dfs, nx, ny);
			}
		};

	dfs(dfs, 0, 0);
	int t = 0;
	while (true)
	{
		vpi zcd;
		bool flag = false;
		for (int i = 0; i < Q.size(); i++)
		{
			if (!inQ[i]) continue;
			flag = true;
			int cnt = 0;
			for (int j = 0; j < 4; j++)
			{
				int nx = Q[i].first + dx[j];
				int ny = Q[i].second + dy[j];
				if (isInrange(nx, ny))
				{
					if (grid[nx][ny] == -1) cnt++;
				}
			}
			if (cnt >= 2)
			{
				for (int j = 0; j < 4; j++)
				{
					int nx = Q[i].first + dx[j];
					int ny = Q[i].second + dy[j];
					if (isInrange(nx, ny))
					{
						if (grid[nx][ny] == 0) zcd.push_back({ nx,ny });
					}
				}
				inQ[i] = false;
			}
		}
		if (!flag) break;
		t++;
		for (int i = 0; i < Q.size(); i++)
		{
			if (!inQ[i] && grid[Q[i].first][Q[i].second] == 1)
				grid[Q[i].first][Q[i].second] = -1;
		}
		for (auto p : zcd)
			dfs(dfs, p.first, p.second);
	}
	cout << t << '\n';
}