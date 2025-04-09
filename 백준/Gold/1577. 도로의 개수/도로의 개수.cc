#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	typedef long long ll;
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> grid(N + 1, vector<ll>(M + 1));

	int K;
	cin >> K;
	set<pair<pair<int,int>,pair<int,int>>> mp;
	for (int i = 0; i < K; i++)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		pair<ll, ll> p = { a,b };
		pair<ll, ll> q= { c,d };
		if (p > q) swap(p, q);
		mp.insert({p,q});
	}

	int dx[2] = { 0,1 };
	int dy[2] = { 1,0 };

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vector<vector<bool>> visited(N+1, vector<bool>(M+1));
	grid[0][0] = 1;
	
	while (!q.empty())
	{
		pair<int, int> here = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int nx = here.first + dx[i];
			int ny = here.second + dy[i];
			if (0 <= nx && nx <= N && 0 <= ny && ny <= M)
			{
				if (mp.find({ here,{nx,ny} }) == mp.end())
				{
					grid[nx][ny] += grid[here.first][here.second];
					if (!visited[nx][ny])
					{
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	
	cout << grid[N][M];
}