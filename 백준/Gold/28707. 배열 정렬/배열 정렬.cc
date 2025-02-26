#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

struct e_data
{
	int u;
	int v;
	int c;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vi v(N);
	for (auto& i : v) cin >> i;
	int M;
	cin >> M;

	vector<e_data> edge(M);

	for (auto& i : edge) cin >> i.u >> i.v >> i.c;

	priority_queue<pair<int, vector<int>>> pq;
	map<vi, int> mp;
	mp.insert({ v,0 });
	pq.push({ 0,v });

	while (!pq.empty())
	{
		vi here = pq.top().second;
		int hereDist = -pq.top().first;
		pq.pop();

		if (hereDist > mp[here]) continue;

		for (int i = 0; i < M; i++)
		{
			vi cp = here;
			swap(cp[edge[i].u-1], cp[edge[i].v-1]);
			int nextDist = hereDist + edge[i].c;

			if (mp.find(cp) != mp.end() && mp[cp] <= nextDist) continue;

			mp[cp] = nextDist;
			pq.push({ -nextDist, cp });
		}
	}

	vi standard = v;
	sort(standard.begin(), standard.end());

	if (mp.find(standard) == mp.end()) cout << -1;
	else cout << mp[standard];
}