#include <bits/stdc++.h>

using namespace std;

int solve(int x)
{
	int ans = 0;
	for (int i = (x >> 2) << 2; i <= x; i++)
		ans ^= i;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		int S, F;
		cin >> S >> F;

		int ret = (solve(F)) ^ (solve(S - 1));
		cout << ret << '\n';
	}
}