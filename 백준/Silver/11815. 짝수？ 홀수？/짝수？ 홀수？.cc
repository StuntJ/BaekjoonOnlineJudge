#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		long long x;
		cin >> x;
		if ((long long)sqrt(x) * (long long)sqrt(x) == x) cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}