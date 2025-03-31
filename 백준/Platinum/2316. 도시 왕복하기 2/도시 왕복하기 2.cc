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

const int MAX_V = 810;
const int INF = 987654321;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int level[MAX_V]; //정점의 레벨을 알려준다.
int work[MAX_V]; //어디까지 탐색했는지 알려주는 배열
vector<int> adj[MAX_V]; //그래프

bool bfs(int source, int sink)
{
	fill(level, level + MAX_V, -1); //모든 정점의 레벨을 1로 초기화
	level[source] = 0; //source의 레벨은 0
	queue<int> q; //bfs탐색에 사용할 queue이다.
	q.push(source); //source를 bfs에 넣어 레벨그래프를 만들어 간다.
	while (!q.empty())
	{
		int here = q.front(); q.pop();
		for (int i = 0; i < adj[here].size(); i++) //간선 탐색
		{
			int there = adj[here][i];
			if (level[there] == -1 && capacity[here][there] - flow[here][there] > 0) //다음 정점의 레벨이 매겨지지 않었고, capactiy-flow가 0보다 크다면
			{
				level[there] = level[here] + 1; //다음 정점의 레벨을 현재 정점 + 1로 잡고
				q.push(there); //queue에 넣어 탐색을 계속한다.
			}
		}
	}
	return level[sink] != -1; //sink까지 레벨 그래프를 만들 수 없으면 false, 만들 수 있다면 true를 리턴한다.
}

int dfs(int here, int sink, int cost) //sink에 도달하면 cost를, 더 이상 탐색을 진행할 수 없다면 0을 리턴한다.
{
	if (here == sink) return cost; //sink에 도달했다면 cost를 리턴한다. 이때 cost는 탐색한 경로로 보낼 수 있는 최대 유량이다.

	for (int& i = work[here]; i < adj[here].size(); i++) //이미 유량을 보낸 간선은 다음 그래프까지 볼 필요가 없으므로, 어디까지 탐색했는지 work에 저장하여, 탐색 안한 곳 부터 탐색하도록 한다.
	{
		int there = adj[here][i];
		if (capacity[here][there] - flow[here][there] > 0 && level[there] == level[here] + 1) //capacity-flow>0 이고 다음 정점의 레벨이 현재 정점보다 1 높으면
		{
			int ret = dfs(there, sink, min(cost, capacity[here][there] - flow[here][there])); //다음 정점을 탐색한다.(sink가 나올 때까지) cost는 capacity-flow보다 클 수는 없지만 최대한 cost를 살려야한다.

			if (ret > 0) //레벨 그래프 경로로 보낼 수 있는 유량이 1이상이면
			{
				flow[here][there] += ret; //양의 유량을 here에서 there로
				flow[there][here] -= ret; //양의 유량이 있다면 음의 유량도 있다는 사실을 잊지 말자.
				return ret; //보낸 최대 유량을 리턴한다.
			}
		}
	}
	return 0; //더 이상 탐색이 불가능하고 sink가 아니면 0을 리턴 한다.
}

int dinicsNetworkFlow(int source, int sink)
{
	int totalFlow = 0; //최대 유량을 저장하는 변수
	while (bfs(source, sink))
	{
		fill(work, work + MAX_V, 0); //i번 정점이 몇 번째 간선까지 탐색했는지 저장하는 배열
		while (1)
		{
			int flow = dfs(source, sink, INF); //dfs로 현재 레벨 그래프의 경로로 유량을 보냈을 때 최대 유량을 리턴한다.
			if (flow == 0) break; //더 이상 추가할 유량이 없으면 반복문에서 빠져 나온다.
			totalFlow += flow; //추가한 유량을 total에 더 한다.
		}
	}
	return totalFlow; //최대 유량 리턴
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int source = 2;
	const int sink = 5;
	int N, P;
	cin >> N >> P;

	auto convert = [&](int x, bool s)
		{
			if (s) return 2 * x;
			else return 2 * x + 1;
		};

	for (int i = 1; i <= N; i++)
	{
		int is = convert(i, 1);
		int ie = convert(i, 0);

		adj[is].emplace_back(ie);
		adj[ie].emplace_back(is);
		capacity[is][ie] = 1;
		if (i == 1 || i == 2)
		{
			capacity[is][ie] = INF;
		}
 	}

	for (int i = 0; i < P; i++)
	{
		int a, b;
		cin >> a >> b;

		int as = convert(a, 1);
		int bs = convert(b, 1);
		int ae = convert(a, 0);
		int be = convert(b, 0);

		adj[ae].emplace_back(bs);
		adj[be].emplace_back(as);
		adj[as].emplace_back(be);
		adj[bs].emplace_back(ae);

		capacity[ae][bs] = INF;
		capacity[be][as] = INF;
	}

	cout << dinicsNetworkFlow(source, sink);
}