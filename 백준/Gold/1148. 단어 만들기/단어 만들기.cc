#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<unordered_map<char,int>> vstr;
	while (true)
	{
		string str;
		cin >> str;
		unordered_map<char, int> mp;
		if (str == "-") break;
		for (auto i : str)
			mp[i]++;
		vstr.emplace_back(mp);
	}

	while (true)
	{
		string str;
		cin >> str;
		if (str == "#") break;
		unordered_map<char, int> mp;
		unordered_map<char, int> res;
		for (auto i : str)
		{
			mp[i]++;
			if (res.find(i) == res.end())
				res[i] = 0;
		}
		
		for (auto vmp : vstr)
		{
			bool flag = false;
			for (auto i : vmp)
			{
				if (!(mp.find(i.first) != mp.end() && mp[i.first] >= i.second)) flag = true;
			}
			if (flag) continue;
			for (auto el : mp)
			{
				if (vmp.find(el.first) != vmp.end() && vmp[el.first] <= el.second)
					res[el.first]++;
			}
		}

		int m = INT_MAX, M = 0;
		for (auto i : res)
		{
			m = min(m, i.second);
			M = max(M, i.second);
		}
		if (m == INT_MAX) m = 0;

		set<char> mini, maxi;
		for (auto i : res)
		{
			if (i.second == m) mini.insert(i.first);
			if (i.second == M) maxi.insert(i.first);
		}

		for (auto i : mini) cout << i;
		cout << ' ' << m << ' ';
		for (auto i : maxi) cout << i;
		cout << ' ' << M << '\n';
	}
}