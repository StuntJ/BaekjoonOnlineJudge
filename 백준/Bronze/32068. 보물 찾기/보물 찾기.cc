#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		ll L, S, R;
		cin >> L >> R >> S;
		if (S - L < R - S) cout << (S - L) * 2+1 << '\n';
		else cout << (R - S) * 2  << '\n';
	}
}