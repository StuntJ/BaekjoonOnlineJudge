#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> even, odd;
	for (int i = 1; i <= 100; i++)
	{
		if (i & 1) odd.emplace_back(i);
		else even.emplace_back(i);
	}
	const int st = 24;

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		int cnt = 0;
		bool line = false; //even
		if (N & 1)
		{
			line = true;
			cnt++;
		}

		int s = 0, e = 49;
		int ans;
		while (s <= e)
		{
			cnt++;
			int mid = (s + e) / 2;
			if (line)
			{
				if (odd[mid] == N)
				{
					break;
				}
				else if (odd[mid] < N)
				{
					s = mid + 1;
				}
				else
				{
					e = mid - 1;
				}
			}
			else
			{
				if (even[mid] == N)
				{
					break;
				}
				else if (even[mid] < N)
				{
					s = mid + 1;
				}
				else
				{
					e = mid - 1;
				}
			}
		}
		cout << cnt << '\n';
	}
}