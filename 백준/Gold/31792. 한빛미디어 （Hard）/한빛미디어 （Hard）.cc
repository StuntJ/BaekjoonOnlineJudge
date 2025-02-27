#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q;
	cin >> Q;

	map<int, int> mp;
	while (Q--)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int p;
			cin >> p;
			mp[p]++;
		}
		else if (q == 2)
		{
			int p;
			cin >> p;
			if (mp.find(p) != mp.end())
				if (--mp[p] == 0) mp.erase(p);	
		}
		else
		{
			auto it = mp.begin();
			int cnt = 0;
			while (it != mp.end())
			{
				it = mp.upper_bound((*it).first * 2-1);
				cnt++;
			}
			cout << cnt << '\n';
		}
	}
}