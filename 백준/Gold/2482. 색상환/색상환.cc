#include <bits/stdc++.h>
#define DIV 1000000003
using namespace std;

typedef long long ll;

vector<vector<vector<vector<ll>>>> cache;
int N, K;

ll solve(int n, int k, int bf, int b)
{
	if (b == 0 && n == N)
	{
		if (k == K) return 1;
		else return 0;
	}
	if (b == 1 && n == N - 1)
	{
		if (k == K)	return 1;
		else return 0;
	}
	if (k > K) return 0;
	ll& ret = cache[n][k][bf][b];
	if (ret != -1) return ret;
	ret = 0;
	if(bf==0) ret += solve(n + 1, k + 1, 1, b);
	ret %= DIV;
	ret += solve(n + 1, k, 0, b);
	ret %= DIV;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (K * 2 > N)
	{
		cout << 0;
		return 0;
	}

	cache = vector<vector<vector<vector<ll>>>>(N + 1, vector<vector<vector<ll>>>(K + 1, vector<vector<ll>>(2, vector<ll>(2, -1))));

	ll ans1 = solve(1, 0, 0, 0);
	ans1 += solve(1, 1, 1, 1);
	ans1 %= DIV;
	cout << ans1;
}