#include <bits/stdc++.h>
#define MAX_V 220
#define INF 987654321

using namespace std;
//MCMF는 Minimum Cost Maximum Flow의 약자로 가중치가 달린, 즉, 간선 하나에 용량과 가중치가 함께 달려있는 그래프에서
//최소한의 비용으로 최대유량을 뽑아내는 알고리즘이다.
//비용은 일반적으로 (흘려보낸 유량) * (간선의 비용) 의 총합이다.
// 이 총합을 최대한 줄이면서 최대 유량을 보내는 것이다.
// 총합을 최대한 줄이려면 최단경로를 따라가야 하는데, 그때 쓰이는 알고리즘이 바로 SPFA알고리즘이다.
// SPFA알고리즘에 유량이 남아있어야 한다는 조건을 하나 더 넣으면 된다.
// 그렇게 경로를 구하고 나머지는 에드몬드 카프 알고리즘과 똑같다.
// 생각해야 할 점은 유량이 음수로 보내질 시, 비용도 음수가 된다는 것이다.

vector<vector<int>> adj; //그래프 (어디로 이동할지만 빠르게 정하기 위해 선언하였다.)
int edgeCost[MAX_V][MAX_V]; //그래프의 가중치
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V]; //간선의 용량을 저장하는 배열, 흐름을 저장하는 배열이다.

pair<int, int> MCMF(int source, int sink)
{
	int totalCost = 0; //총 비용을 저장할 변수
	int totalFlow = 0; //최대 유량을 저장할 변수
	while (true)
	{
		vector<int> parent(MAX_V, -1); //에드몬드 카프 알고리즘에서 경로를 형성하기 위한 변수
		vector<int> dist(MAX_V, INF); //SPFA에서 거리를 저장하는 변수
		vector<bool> inQ(MAX_V, false); //SPFA에서 정점이 queue안에 있는지 확인하는 변수
		queue<int> q; //SPFA에서 탐색에 사용하는 queue
		dist[source] = 0; //지금 있는 곳과의 거리는 0이다.
		parent[source] = source; //source의 부모는 없으므로 source로 설정해 놓는다.
		q.push(source); //queue에 source를 넣는다.
		inQ[source] = true; //queue에 들어갔으므로 inQ[source] 를 true로 바꾼다.

		while (!q.empty()) //모두 탐색할 때까지
		{
			int here = q.front(); //queue에서 정점을 꺼낸다.
			q.pop(); //queue에서 정점을 제거한다.
			inQ[here] = false; //정점이 제거되었으므로 inQ 비활성화

			for (auto there : adj[here]) //탐색
			{
				if (capacity[here][there] - flow[here][there] > 0 && dist[there] > dist[here] + edgeCost[here][there]) //조건이 2개인데 하나는 완화가 일어날 조건, 하나는 유량을 보낼 수 있는 조건이다.
				{
					dist[there] = dist[here] + edgeCost[here][there]; //완화
					parent[there] = here; //경로 형성
					if (!inQ[there]) //queue에 탐색한 정점이 없다면
					{
						q.push(there); //queue 에 정점을 넣는다.
						inQ[there] = true; //정점이 들어갔으므로 inQ 활성화
					}
				}
			}
			//SPFA에서 하는 것처럼 음수 사이클을 판정 안하는 이유는 음수사이클이 절대 만들어질 수 없기 때문이다. (증명되어있는 것)
		}
		if (parent[sink] == -1) break; //경로가 끝까지 만들어지지 않았다면 더 이상 유량을 보낼 수 없으므로 break

		int amount = INF; //보낼 수 있는 유량
		for (int p = sink; p != source; p = parent[p]) //보낼 수 있는 유량을 경로를 따라가며 계산해준다.
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);

		totalFlow += amount; //계산된 유량을 totalFlow에 더한다.

		for (int p = sink; p != source; p = parent[p]) //경로를 따라가며
		{
			totalCost += edgeCost[parent[p]][p] * amount; //totalCost 에 가중치와 흐르는 유량을 곱하여 더한다.
			flow[parent[p]][p] += amount; //flow에 양의 유량
			flow[p][parent[p]] -= amount; //반대 flow에는 음의 유량
		}
	}
	return make_pair(totalFlow, totalCost); //결과를 반환한다.
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int source = 0;
	const int sink = 210;

	int N, M;
	cin >> N >> M;

	adj.resize(220);
	vector<int> A(N), B(M);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;

	for (int i = 1; i <= M; i++)
	{
		capacity[source][i] = B[i-1];
		edgeCost[source][i] = 0;


		adj[source].emplace_back(i);
		adj[i].emplace_back(source);
	}

	for (int i = M + 1; i <= M + N; i++)
	{
		capacity[i][sink] = A[i-M-1];
		edgeCost[source][i] = 0;

		adj[sink].emplace_back(i);
		adj[i].emplace_back(sink);
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = M + 1; j <= M + N; j++)
		{
			adj[i].emplace_back(j);
			adj[j].emplace_back(i);
			cin >> capacity[i][j];
		}
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = M + 1; j <= M + N; j++)
		{
			cin >> edgeCost[i][j];
			edgeCost[j][i] = -edgeCost[i][j];
		}
	}

	pair<int, int> p = MCMF(source, sink);
	cout << p.first << '\n' << p.second;
}