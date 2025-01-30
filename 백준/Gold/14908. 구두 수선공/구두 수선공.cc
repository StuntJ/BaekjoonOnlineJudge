#include <bits/stdc++.h>

using namespace std;

struct pq_data
{
	int day;
	int cost;
	int idx;

	bool operator < (const pq_data& rhs) const
	{
		int totday = day + rhs.day;

		if ((cost * totday + rhs.day * rhs.cost) == (rhs.cost * totday + day * cost)) return idx < rhs.idx;
		return (cost * totday + rhs.day * rhs.cost) > (rhs.cost * totday + day * cost);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<pq_data> v;
	for (int i = 0; i < N; i++)
	{
		pq_data node;
		cin >> node.day >> node.cost;
		node.idx = i + 1;
		v.push_back(node);
	}
	sort(v.begin(), v.end());

	for (auto i : v) cout << i.idx << ' ';
}