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
		int n;
		cin >> n;
		for (int i = 0; i <= 20; i++)
		{
			if (n & (1 << i)) cout << i << ' ';
		}
		cout << '\n';
	}
}