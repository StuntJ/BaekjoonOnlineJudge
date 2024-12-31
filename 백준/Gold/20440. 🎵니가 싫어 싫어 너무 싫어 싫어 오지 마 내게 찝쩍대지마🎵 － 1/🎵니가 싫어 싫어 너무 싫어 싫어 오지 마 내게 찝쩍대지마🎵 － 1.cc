#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<int, int> mp;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		mp[x]++;
		mp[y]--;
	}
	vector<pair<int, int>> v(mp.begin(), mp.end());

	//for (auto i : v) cout << i.first << ' ' << i.second << '\n';

	int max = 0;
	int tot = 0;
	int st = 0;
	int nd = 0;
	bool flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		tot += v[i].second;
		if (tot > max)
		{
			st = v[i].first;
			max = tot;
			flag = true;
		}
		else if (tot == max)
		{
			if (flag)
				nd = v[i].first;
		}
		else
		{
			if (flag)
			{
				flag = false;
				nd = v[i].first;
			}
		}
	}
	cout << max << '\n';
	cout << st << ' ' << nd << '\n';
}