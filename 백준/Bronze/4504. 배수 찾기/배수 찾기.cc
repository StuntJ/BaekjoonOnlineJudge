#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (true)
	{
		int x;
		cin >> x;
		if (x == 0) break;

		if (x % n) cout << x << " is NOT a multiple of " << n << ".\n";
		else cout << x << " is a multiple of " << n << ".\n";
	}
}