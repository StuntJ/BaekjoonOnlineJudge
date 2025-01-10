#include <bits/stdc++.h>

using namespace std;

bool operator < (pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	priority_queue<int,vector<int>,greater<int>> remain;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end());
	vector<int> cnt;
	for (int i = 0; i < N; i++)
	{
		while (!pq.empty() && v[i].first >= pq.top().first)
		{
			remain.push(pq.top().second);
			pq.pop();
		}
		if (remain.empty())
		{
			cnt.push_back(1);
			pq.push({ v[i].second,pq.size() });
		}
		else
		{
			cnt[remain.top()]++;
			pq.push({ v[i].second,remain.top() });
			remain.pop();
		}
	}

	cout << cnt.size() << '\n';
	for (auto i : cnt) cout << i << ' ';
}