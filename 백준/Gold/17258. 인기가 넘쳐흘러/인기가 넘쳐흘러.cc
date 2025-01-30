#include <bits/stdc++.h>

using namespace std;

int cache[301][301];
vector<pair<int, int>> v_data;
int N, M, K, T;

int solve(int here, int rem, int prev)
{
	if (here == v_data.size()) return 0;
	int& ret = cache[here][rem];
	if (ret != 0) return ret;

	int cost = max(0, T - v_data[here].second);
	int rcost = (prev >= cost) ? 0 : cost;
	
	if (rem - rcost >= 0) return ret = max(solve(here + 1, rem - rcost, cost) + v_data[here].first, solve(here + 1, rem, 0));
	else return ret = solve(here + 1, rem, 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K >> T;

	vector<int> v(N + 2);
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s]++;
		v[e]--;
	}


	for (int i = 1; i <= N + 1; i++)
		v[i] += v[i - 1];
	
	for (int i = 1; i <= N + 1; i++)
		v[i] = min(v[i], T);
		
	
	int temp = v[1];
	int cnt = 1;
	for (int i = 2; i <= N; i++)
	{
		if (temp != v[i])
		{
			v_data.emplace_back(make_pair(cnt, temp));
			cnt = 0;
			temp = v[i];
		}
		cnt++;
	}
	v_data.emplace_back(make_pair(cnt, temp));

	//for (auto i : v_data) cout << i.first << ' ' << i.second << '\n';
	cout << solve(0, K, 0);

}