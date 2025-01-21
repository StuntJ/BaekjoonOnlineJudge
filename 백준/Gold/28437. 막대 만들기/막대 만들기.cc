#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;

int cache[MAX_N];

int solve(int x, set<int>& a)
{
	if (x == 0) return 0;
	int& ret = cache[x];
	if (ret != -1) return ret;
	ret = 0;
	if (a.find(x) != a.end()) ret++;
	if (x == 1) return ret;
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			if (i * i == x) ret += solve(i, a);
			else
			{
				ret += solve(i, a);
				if(x/i!=x) ret += solve(x / i, a);
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	set<int> A;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.insert(x);
	}

	int M;
	cin >> M;
	vector<int> B(M);
	for (auto& i : B) cin >> i;

	memset(cache, -1, sizeof(cache));
	for (auto x : B)
	{
		cout << solve(x, A) << ' ';
	}
}