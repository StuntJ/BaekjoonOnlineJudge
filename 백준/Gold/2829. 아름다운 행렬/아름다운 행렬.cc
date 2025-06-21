#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));
	for (auto& i : v)
		for (auto& j : i)
			cin >> j;

	vector<vector<int>> rv = v;

	for (int i = 0; i < N; i++) {
		int x = i;
		int y = 0;
		while (x + 1 < N && y + 1 < N) {
			v[x + 1][y + 1] += v[x][y];
			x++; y++;
		}
	}

	for (int i = 0; i < N; i++) {
		int x = i;
		int y = N-1;
		while (x + 1 < N && y - 1 >=0) {
			rv[x + 1][y - 1] += rv[x][y];
			x++; y--;
		}
	}


	for (int i = 1; i < N; i++) {
		int x = 0;
		int y = i;

		while (x + 1 < N && y + 1 < N) {
			v[x + 1][y + 1] += v[x][y];
			x++; y++;
		}
	}

	for (int i = 0; i < N-1; i++) {
		int x = 0;
		int y = i;

		while (x + 1 < N && y - 1 >= 0) {
			rv[x + 1][y - 1] += rv[x][y];
			x++; y--;
		}
	}
/*
	for (auto i : v) {
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}

	for (auto i : rv) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}*/

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k = 1;
			int lu = ((i-1>=0 && j-1>=0) ? v[i - 1][j - 1] : 0);
			
			//cout << i << ' ' << j << ' ' << lu << ' ' << ru << '\n';
			while (i + k < N && j + k < N) {
				int ru = ((i-1>=0 && j+k+1<N) ? rv[i - 1][j + k + 1] : 0);
				int temp = (v[i + k][j + k] - lu) - (rv[i + k][j] - ru);
				ans = max(ans, temp);
				k++;
			}
		}
	}
	cout << ans;
	
}