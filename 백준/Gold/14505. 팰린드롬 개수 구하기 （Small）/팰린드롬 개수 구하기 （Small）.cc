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

	string str;
	cin >> str;

	int N = str.size();

	vvll dp(N, vll(N, 0));

	for (int i = 0; i < N; i++)
		dp[i][i] = 1;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; i + j < N; j++)
		{
			if (i == 1) dp[j][j + i] = 2 + (str[j] == str[j + i]);
			else
			{
				if (str[j] != str[j + i]) dp[j][i + j] = (dp[j + 1][i + j] + dp[j][i + j - 1] - dp[j + 1][i + j - 1]);
				else dp[j][i + j] = (dp[j + 1][i + j] + dp[j][i + j - 1] + 1);
			}
		}
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}*/
	cout << dp[0][N - 1] << '\n';
}