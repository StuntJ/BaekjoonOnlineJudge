#include <bits/stdc++.h>

using namespace std;

int solve(map<int, int>& mp)
{
	if (mp.empty()) return 0;
	auto it = mp.begin();
	int val = (*it).first * 2 - 1;
	int cnt = 1;
	while ((it = mp.upper_bound(val)) != mp.end())
	{
		cnt++;
		val = (*it).first * 2 - 1;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q;
	cin >> Q;
	map<int, int> mp;
	while (Q--)
	{
		int qu;
		cin >> qu;
		if (qu == 1)
		{
			int cost;
			cin >> cost;

			if (mp.find(cost) == mp.end()) mp.insert(make_pair(cost, 1));
			else mp[cost]++;
		}
		else if (qu == 2)
		{
			int cost;
			cin >> cost;
			if (mp.find(cost) == mp.end()) continue;
			if (--mp[cost] == 0) mp.erase(cost);
		}
		else
		{
			cout << solve(mp) << '\n';
		}
	}
}