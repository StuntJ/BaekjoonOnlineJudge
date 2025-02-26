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

struct disjoint_set
{
	vector<int> parent;
	disjoint_set(int n) : parent(n)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) //정점이 어느 집합에 속하는지 알려주는 함수이다.
	{
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v) //u와 v를 같은 집합에 속하게 하는 함수이다.
	{
		u = find(u); v = find(v);
		if (u == v) return false;
		parent[u] = v;
		return true;
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vi v(M);
    for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());

    vi q(K);
    for (auto& i : q) cin >> i;

	disjoint_set d_set(M+1);

	for (auto f : q)
	{
		int idx = upper_bound(v.begin(), v.end(), f) - v.begin();
		idx = d_set.find(idx);
		cout << v[idx] << '\n';
		d_set.merge(idx, idx + 1);
	}
}