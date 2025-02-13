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

	int N;
	cin >> N;

	vvc board = vvc(N, vc(2 * N - 1,' '));

	auto solve = [&](auto& solve, int x, int y, int n) ->void
		{
			if (n == 3)
			{
				board[x][y + 2] = '*';
				board[x + 1][y + 1] = '*';
				board[x + 1][y + 3] = '*';
				for (int i = 0; i < 5; i++)
					board[x + 2][y + i] = '*';
			}
			else
			{
				solve(solve, x, y + n / 2, n / 2);
				solve(solve, x + n / 2, y, n / 2);
				solve(solve, x + n / 2, y + n, n / 2);
			}
			return;
		};

	solve(solve, 0, 0, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
			cout << board[i][j];
		cout << '\n';
	}
}