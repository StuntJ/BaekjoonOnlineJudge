#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int lim = (int)floor(log2(100000));

vector<vector<pair<ll, ll>>> adj;
vector<ll> s, e, c;
vector<ll> weight, depth, parent, newCost;
vector<vector<ll>> dp;
vector<ll> head, comp, lab;
ll piv1, piv2;
int N, Q;

struct RMQ
{
	int n;
	vector<ll> rangeMin;
	RMQ(const vector<ll>& array)
	{
		n = array.size();
		rangeMin.resize(n * 4); //대충 n*4정도 할당하면 맞음
		init(array, 1, 0, n - 1); //rangeMin 배열 초기화
	}

	int init(const vector<ll>& array, int node, int nodeLeft, int nodeRight)
	{
		if (nodeLeft == nodeRight) return rangeMin[node] = array[nodeLeft]; //nodeLeft==nodeRight면 array값을 rangeMin[node]에 그대로 넣는다.
		int mid = (nodeLeft + nodeRight) / 2;
		ll leftMin = init(array, node * 2, nodeLeft, mid); //구간 반으로 쪼개고 그 반에서 최솟값을 구한다.
		ll rightMin = init(array, node * 2 + 1, mid + 1, nodeRight); //구간 반으로 쪼개고 그 반에서 최솟값을 구한다.
		return rangeMin[node] = max(leftMin, rightMin); //양 구간에서 나온 최솟값을 rangeMin[node]에 저장한다.
	}

	const int INTMAX = numeric_limits<ll>::min();
	ll query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (nodeRight < left || right < nodeLeft) return INTMAX; //구간을 벗어났을 경우 return 값을 무시하기 위해 항등원 INTMAX를 return 한다.
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node]; //구간안에 완전히 들어온 경우 값을 리턴한다.
		int mid = (nodeLeft + nodeRight) / 2;
		return max(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight)); //두개의 쪼개진 구간에서 작은 값을 리턴한다.
	}

	ll query(int left, int right) //주의 함수의 return 자료형을 typedef로 선언하면 오버로딩이 불가능
	{
		return query(left, right, 1, 0, n - 1);
	}

	ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index) return rangeMin[node]; //변경되는 index값을 벗어난 구간이면 그냥 있는 값을 리턴한다.
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue; //index에 도달했으면 rangeMin[node] 에 newValue를 넣는다.
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = max(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight)); //두 개의 쪼개진 구간에서 최솟값을 받아 현재 노드에 넣는다.
	}

	ll update(int index, ll newValue) //주의 함수의 return 자료형을 typedef로 선언하면 오버로딩이 불가능
	{
		return update(index, newValue, 1, 0, n - 1);
	}
};

void dfs(int here, int p = 0)
{
	weight[here] = 1;
	for (auto& i : adj[here])
	{
		ll next = i.first;
		ll cost = i.second;
		if (next == p) continue;
		depth[next] = depth[here] + 1;
		dp[0][next] = here;
		parent[next] = here;
		newCost[next] = cost;
		dfs(next, here);
		weight[here] += weight[next];
	}
}

void makeTable()
{
	for (int i = 1; i <= lim; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
}

void hld(int here, int p = 0)
{
	sort(adj[here].begin(), adj[here].end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
		{
			return weight[a.first] > weight[b.first];
		});

	int heavy = -1;
	for (auto& i : adj[here])
	{
		int next = i.first;
		if (next == p) continue;
		heavy = next;
		comp[next] = comp[here];
		lab[next] = ++piv2;
		hld(next, here);
		break;
	}

	for (auto& i : adj[here])
	{
		int next = i.first;
		if (next == heavy || next == p) continue;
		comp[next] = ++piv1;
		head[piv1] = next;
		lab[next] = ++piv2;
		hld(next, here);
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];
	for (int i = 0; diff; i++)
	{
		if (diff & 1) a = dp[i][a];
		diff >>= 1;
	}

	for (int i = lim; i >= 0; i--)
	{
		if (dp[i][a] != dp[i][b]) a = dp[i][a], b = dp[i][b];
	}
	if (a == b) return a;
	return dp[0][a];
}

void update(int idx, int val, RMQ& segTree)
{
	if (depth[s[idx]] > depth[e[idx]]) swap(s[idx], e[idx]);
	segTree.update(lab[e[idx]], val);
}

ll sub_query(int s, int e, RMQ& segTree)
{
	ll ret = 0;
	while (comp[s] != comp[e])
	{
		int ss = head[comp[s]], ee = head[comp[e]];
		if (depth[ss] > depth[ee])
		{
			ret = max(ret, segTree.query(lab[ss], lab[s]));
			s = parent[ss];
		}
		else
		{
			ret = max(ret, segTree.query(lab[ee], lab[e]));
			e = parent[ee];
		}
	}
	if (depth[e] > depth[s]) swap(s, e);
	ret = max(ret, segTree.query(lab[e] + 1, lab[s]));
	return ret;
}

ll query(int u, int v, RMQ& segTree)
{
	int t = lca(u, v);
	return max(sub_query(u, t, segTree), sub_query(v, t, segTree));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	adj = vector<vector<pair<ll, ll>>>(N + 1);
	s = vector<ll>(N + 1);
	e = vector<ll>(N + 1);
	c = vector<ll>(N + 1);
	weight = vector<ll>(N + 1);
	depth = vector<ll>(N + 1);
	parent = vector<ll>(N + 1);
	newCost = vector<ll>(N + 1);
	dp = vector<vector<ll>>(lim + 1, vector<ll>(N + 1));
	comp = vector<ll>(N + 1);
	head = vector<ll>(N + 1);
	lab = vector<ll>(N + 1);

	for (int i = 1; i < N; i++)
	{
		cin >> s[i] >> e[i] >> c[i];

		adj[s[i]].push_back({ e[i],c[i] });
		adj[e[i]].push_back({ s[i],c[i] });
	}
	dfs(1);
	makeTable();
	head[1] = comp[1] = lab[1] = piv1 = piv2 = 1;
	hld(1);

	vector<ll> v(N + 1);
	for (int i = 1; i <= N; i++)
	{
		v[lab[i]] = newCost[i];
	}
	RMQ segTree(v);
	cin >> Q;

	while (Q--)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int idx, val;
			cin >> idx >> val;
			update(idx, val,segTree);
		}
		else
		{
			int u, v;
			cin >> u >> v;
			cout << query(u, v, segTree) << '\n';
		}
	}
}