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
	vector<int> parent; //어느 집합에 속하는 지 저장할 배열과, 집합의 깊이가 얼마나 깊은지 나타내는 rank
	disjoint_set(int n) : parent(n)//0 ~ n-1 의 정점에 대한 집합. 초기 rank는 모두 1이다.
	{
		for (int i = 0; i < n; i++) //parent가 모두 자기 자신을 가르키게 놓는다.
			parent[i] = i;
	}

	int find(int u) //정점이 어느 집합에 속하는지 알려주는 함수이다.
	{
		if (u == parent[u]) return u; //parent가 자기 자신을 가르킨다면 자기 자신을 리턴한다.
		return parent[u] = find(parent[u]); //자신이 어디에 속하는지 parent를 따라가며 탐색한다. 그 최종결과를 u는 바로 parent로 맞이해서 집합의 깊이를 줄일 것이다.
	}

	bool merge(int u, int v) //u와 v를 같은 집합에 속하게 하는 함수이다.
	{
		u = find(u); v = find(v); //u와 v를 대표하는 조상을 각각 찾는다.
		if (u == v) return false; //u와 v의 조상이 같다면 같은 집합에 속하므로 합칠 수 없다. false를 리턴한다.
		if (u < v) swap(u, v);
		parent[u] = v; //u의 조상을 v로 만든다.
		return true; //u와 v를 같은 집합에 속하게 하는데에 성공하였다. true를 리턴한다.
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int G, P;
	cin >> G >> P;

	disjoint_set ds(G + 1);

	int ans = 0;
	vi seq(P);

	for (auto& i : seq) cin >> i;
	for (int i = 0; i < P; i++)
	{
		int x = seq[i];
		if (ds.find(x) == 0) break;
		ds.merge(ds.find(x) - 1,x);
		ans++;
	}
	cout << ans << '\n';
}