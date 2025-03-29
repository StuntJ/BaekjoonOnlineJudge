#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int N = 10;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int k = 1 << j;
			char x;
			cin >> x;
			if (x == 'O') v[i] |= k;
		}
	}

	int ans = 987654321;
	for (int i = 0; i < (1 << N); i++)
	{
		int cnt = 0;
		vector<int> cp = v;
		for (int j = 0; j < N; j++)
		{
			if ((1 << j) & i)
			{
				cnt++;
				cp[0] ^= (1 << j);
				cp[1] ^= (1 << j);
				if (j > 0) cp[0] ^= (1 << (j - 1));
				if (j < N - 1) cp[0] ^= (1 << (j + 1));
			}
		}

		for (int j = 1; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if ((1 << k) & cp[j - 1])
				{
					cnt++;
					cp[j] ^= (1 << k);
					if (j < N - 1) cp[j + 1] ^= (1 << k);
					if (k > 0) cp[j] ^= (1 << (k - 1));
					if (k < N - 1) cp[j] ^= (1 << (k + 1));
				}
			}
			if (j == N - 1 && cp[j] == 0)
				ans = min(ans, cnt);
		}
	}
	cout << (ans == 987654321 ? -1 : ans);
}