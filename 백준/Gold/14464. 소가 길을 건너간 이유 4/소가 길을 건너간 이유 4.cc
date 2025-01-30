#include <bits/stdc++.h>

using namespace std;

struct comp
{
	bool operator() (pair<int, int>& a, pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C, N;
	cin >> C >> N;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> v(C);
	for (auto& i : v) cin >> i;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	sort(v.begin(), v.end());
	int cnt = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> temp;
	for (auto stand : v)
	{
		while (!pq.empty() && pq.top().first <= stand)
		{
			temp.push(pq.top());
			pq.pop();
		}

		while (!temp.empty() && temp.top().second < stand)
		{
			temp.pop();
		}
		if (!temp.empty())
		{
			cnt++;
			temp.pop();
		}
	}

	cout << cnt;
}