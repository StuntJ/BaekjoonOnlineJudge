#include <bits/stdc++.h>

using namespace std;

int mtx[4][4] = {
	100, 70, 40, 0,
	70, 50, 30, 0,
	40, 30, 20, 0,
	0, 0, 0, 0
};

int comb(char a, char b)
{
	int u, v;
	if (a == 'F') u = a - 'A' - 2;
	else u = a - 'A';
	if (b == 'F') v = b - 'A' - 2;
	else v = b - 'A';
	return mtx[u][v];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);  
	
	int N;
	cin >> N;

	vector<vector<char>> v(N, vector<char>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	vector<vector<int>> cache(N*N, vector<int>(1<<N,-1));

	const int INF = 987654321;
	auto solve = [&](auto& solve, int idx, int stat)
		{
			if (idx >= N * N)
			{
				if (stat == 0) return 0;
				else return -INF;
			}

			int& ret = cache[idx][stat];
			if (ret != -1) return ret;

			ret = solve(solve, idx + 1, stat >> 1);
			if (stat & 1) return ret;

			if ((idx + 1) % N != 0 && (stat & (1 << 1)) == 0)
				ret = max(ret, comb(v[idx / N][idx % N], v[idx / N][idx % N + 1]) + solve(solve, idx + 2, stat >> 2));

			if (idx + N < N * N)
				ret = max(ret, comb(v[idx / N][idx % N], v[idx / N + 1][idx % N]) + solve(solve, idx + 1, (stat >> 1) | (1 << (N - 1))));

			return ret;
		};
	cout << solve(solve, 0, 0);
}