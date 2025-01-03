#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

bool fb[101];
vector<vector<int>> cache;
int N, M;

int solve(int n, int cp)
{
	if (n >= N + 1) return 0;
	int& ret = cache[n][cp];
	if (ret != -1) return ret;
	ret = INF;

	ret = min(ret, solve(n + 1, cp) + 10000);
	ret = min(ret, solve(n + 3, cp + 1) + 25000);
	ret = min(ret, solve(n + 5, cp + 2) + 37000);
	if (fb[n]) ret = min(ret, solve(n + 1, cp));
	if (cp >= 3) ret = min(ret, solve(n + 1, cp - 3));
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		fb[x] = true;
	}

	cache.assign(N + 1, vector<int>(101, -1));
	cout<<solve(1, 0);
}