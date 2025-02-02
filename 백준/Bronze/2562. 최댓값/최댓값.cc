#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M = 0;
	int idx = 0;
	for (int i = 1; i <= 9; i++)
	{
		int x;
		cin >> x;
		if (M < x)
		{
			M = x;
			idx = i;
		}
	}
	cout << M << '\n';
	cout << idx;
}