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
		int A, B;
		cin >> A >> B;

		vector<bool> st(1 << 10);
		while (A > 0)
		{
			st[A] = true;
			A >>= 1;
		}

		int ans = 0;
		while (B > 0)
		{
			if (st[B])
			{
				ans = B;
				break;
			}
			B >>= 1;
		}
		cout << ans*10 << '\n';
	}
}