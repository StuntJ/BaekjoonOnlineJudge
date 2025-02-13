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
	vector<int> parent, rank; //어느 집합에 속하는 지 저장할 배열과, 집합의 깊이가 얼마나 깊은지 나타내는 rank
	disjoint_set(int n) : parent(n), rank(n, 1) //0 ~ n-1 의 정점에 대한 집합. 
	{
		for (int i = 0; i < n; i++) //parent가 모두 자기 자신을 가리키게 놓는다.
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
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
		return true;
	}
};

struct e_data
{
	int a;
	int b;
	int c;
	bool operator < (const e_data& rhs) const
	{
		return c > rhs.c;
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N, M;
	cin >> N >> M;

	priority_queue<e_data> pq;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	disjoint_set d_set(N + 1);
	int total = 0;
	int maximum = 0;
	while (!pq.empty())
	{
		int a = pq.top().a;
		int b = pq.top().b;
		int cost = pq.top().c;
		pq.pop();

		if (!d_set.merge(a, b)) continue;
		maximum = max(cost, maximum);
		total += cost;
	}
	cout << total - maximum;
}