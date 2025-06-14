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

	int T;
	cin >> T;

	int idx = 1;
	while (T--)
	{
		int N;
		cin >> N;
		disjoint_set d(N + 1);
		int K;
		cin >> K;

		while (K--) {
			int a, b;
			cin >> a >> b;
			d.merge(a, b);
		}

		cout << "Scenario " << idx++ << ":\n";
		int P;
		cin >> P;
		while (P--) {
			int a, b;
			cin >> a >> b;
			if (d.find(a) == d.find(b)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}
}