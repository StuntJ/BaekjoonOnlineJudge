#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	set<pair<int, int>> us;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		us.insert({ x,y });
		v.push_back({ x,y });
	}

	static int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i].first>=v[j].first || v[i].second>=v[j].second) continue;
			if (us.find({ v[i].first,v[j].second }) != us.end() && us.find({ v[j].first,v[i].second }) != us.end())
			{
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}