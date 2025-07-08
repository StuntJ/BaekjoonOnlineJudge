#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	vector<vector<char>> grid(2, vector<char>(N));
	vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(N,vector<bool>(4)));
	for (auto& i : grid)
		for (auto& j : i)
			cin >> j;

	auto dfs = [&](auto& dfs, int x, int y, int dir)->void {
		//cout << x << ' ' << y << '\n';
		if (x == 0 && y == 0) return;
		visited[x][y][dir] = true;

		if (grid[x][y] == 'L') {
			int nx1 = x + dx[(dir + 1) % 4];
			int ny1 = y + dy[(dir + 1) % 4];
			int nx2 = x + dx[(dir + 3) % 4];
			int ny2 = y + dy[(dir + 3) % 4];
			if (0 <= nx1 && nx1 < 2 && 0 <= ny1 && ny1 < N && !visited[nx1][ny1][(dir + 1) % 4])
				dfs(dfs, nx1, ny1, (dir + 1) % 4);
			if (0 <= nx2 && nx2 < 2 && 0 <= ny2 && ny2 < N && !visited[nx2][ny2][(dir + 3) % 4])
				dfs(dfs, nx2, ny2, (dir + 3) % 4);
		}
		else if (grid[x][y] == 'I') {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx && nx < 2 && 0 <= ny && ny < N && !visited[nx][ny][dir])
				dfs(dfs, nx, ny, dir);
		}
	};

	dfs(dfs, 0, 1, 0);
	dfs(dfs, 1, 0, 1);
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		flag |= visited[1][N - 1][i];
	}
	cout << (flag ? "YES" : "NO");
}