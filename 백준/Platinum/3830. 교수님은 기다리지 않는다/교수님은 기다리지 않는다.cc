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
	vector<pi> parent;
	disjoint_set(int n) : parent(n)
	{
		for (int i = 0; i < n; i++)
			parent[i] = { i,0 };
	}

	pi find(int u) //정점이 어느 집합에 속하는지 알려주는 함수이다.
	{
		if (u == parent[u].first) return { u,0 };
		int t = parent[u].second;
		pi rt = find(parent[u].first);
		rt.second += t;
		parent[u] = rt;
		return rt;
	}

	bool merge(int u, int v, int cost) //u와 v를 같은 집합에 속하게 하는 함수이다.
	{
		pi ud, vd;
		ud = find(u), vd = find(v);
		if (ud.first == vd.first) return false;
		int tot = cost - ud.second + vd.second;
		parent[ud.first] = { vd.first,tot };
		return true;
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	while (true)
	{
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) return 0;

		disjoint_set d_set(N + 1);
		while (M--)
		{
			char q;
			cin >> q;
			if (q == '!')
			{
				int u, v, c;
				cin >> u >> v >> c;
				d_set.merge(u, v, c);
			}
			else
			{
				int u, v;
				cin >> u >> v;
				pi ud = d_set.find(u);
				pi uv = d_set.find(v);

				if (ud.first != uv.first) cout << "UNKNOWN" << '\n';
				else
				{
					cout << ud.second - uv.second << '\n';
				}
			}
		}
	}
}