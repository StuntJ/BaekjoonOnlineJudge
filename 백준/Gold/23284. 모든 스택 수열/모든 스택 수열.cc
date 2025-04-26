#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v;
	for (int i = N; i >= 1; i--)
	{
		v.push_back(i);
	}
	stack<int> s;
	vector<vector<int>> vstr;
	vector<int> str;
	auto solve = [&](auto& solve, vector<int>& v, stack<int>& s, vector<int>& str)->void
	{
		if (v.empty() && s.empty())
		{
			vstr.push_back(str);
			return;
		}

		if(!v.empty())
		{
			int k = v.back();
			v.pop_back();
			s.push(k);
			solve(solve, v, s, str);
			s.pop();
			v.push_back(k);
		}

		if (!s.empty())
		{
			int k = s.top();
			s.pop();
			str.push_back(k);
			solve(solve, v, s, str);
			s.push(k);
			str.pop_back();
		}
	};
	solve(solve, v, s, str);
	sort(vstr.begin(), vstr.end(), [](vector<int> a, vector<int> b) {
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i]) continue;
			return a < b;
		}
		});
	for (int i = 0; i < vstr.size(); i++)
	{
		for (int j = 0; j < vstr[i].size(); j++)
		{
			cout << vstr[i][j] << ' ';
		}
		cout << '\n';
	}
}