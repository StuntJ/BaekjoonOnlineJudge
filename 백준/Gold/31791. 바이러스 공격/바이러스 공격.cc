#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int Tg, Tb, X, B;
	cin >> Tg >> Tb >> X >> B;

	vector<vector<char>> grid(N, vector<char>(M));

	for (auto& i : grid)
		for (auto& j : i)
			cin >> j;
	vector<vector<int>> v(N, vector<int>(M));
	vector<pair<pair<int,int>,int>> st;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == '#')
				v[i][j] = Tb;
			if (grid[i][j] == '*')
				st.push_back({{i,j},0});
		}
	}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	queue<pair<pair<int,int>,int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M));
	for (auto i : st) {
		q.push(i);
		visited[i.first.first][i.first.second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		//cout << x << ' ' << y << ' ' << t << '\n';
		if (t == Tg) {
			//visited[x][y] = false;
			continue;
		}
		if (v[x][y]) {
			if (t + v[x][y] > Tg) {
				v[x][y] = 1;
				continue;
			}
			else if (t + v[x][y] == Tg)
			{
				v[x][y] = 0;
				continue;
			}
			v[x][y]--;
			q.push({ {x,y},t + 1 });
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!visited[nx][ny]) {
					q.push({ {nx,ny},t + 1 });
					visited[nx][ny] = true;
				}
			}
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!(!v[i][j] && visited[i][j])) {
				ans.push_back({ i + 1,j + 1 });
			}
		}
	}
	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}