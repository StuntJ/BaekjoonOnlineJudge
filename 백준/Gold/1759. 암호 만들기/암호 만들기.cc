#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, C;
	cin >> L >> C;

	string str;
	for (int i = 0; i < C; i++)
	{
		char x;
		cin >> x;
		str.push_back(x);
	}

	sort(str.begin(), str.end());

	string ans;
	vector<string> vstr;
	string vowel = "aeiou";
	auto solve = [&](auto& solve, int here, string& ans)->void
	{
		if (ans.size() == L)
		{
			int vcnt = 0;
			int ecnt = 0;
			for (auto i : ans)
			{
				bool flag = false;
				for (auto j : vowel)
				{
					if (i == j)
					{
						flag = true;
						vcnt++;
						break;
					}
				}
				if (!flag)
					ecnt++;
			}
			if(vcnt>=1&& ecnt>=2)
				vstr.push_back(ans);
			return;
		}
		if (here == C) return;

		ans.push_back(str[here]);
		solve(solve, here + 1, ans);
		ans.pop_back();
		solve(solve, here + 1, ans);
		return;
	};

	solve(solve, 0, ans);

	sort(vstr.begin(), vstr.end());
	
	for (auto i : vstr) cout << i << '\n';
}