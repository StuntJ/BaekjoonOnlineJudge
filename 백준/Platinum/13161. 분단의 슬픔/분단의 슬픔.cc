#include <bits/stdc++.h>
#define S 0
#define T 501
#define MAX_N 502
#define INF 987654321
using namespace std;

int N;
int capacity[MAX_N][MAX_N];
int flow[MAX_N][MAX_N];
int level[MAX_N];
int work[MAX_N];
vector<int> adj[MAX_N];

bool bfs()
{
	memset(level, -1, sizeof(level));
	level[S] = 0;
	queue<int> q;
	q.push(S);

	while (!q.empty())
	{
		int here = q.front(); q.pop();
		for (auto next : adj[here])
		{
			if (level[next] == -1 && capacity[here][next] - flow[here][next] > 0)
			{
				level[next] = level[here] + 1;
				q.push(next);
			}
		}
	}
	return level[T] != -1;
}

int dfs(int here, int cost)
{
	if (here == T) return cost;

	for (int& i = work[here]; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (level[here] + 1 == level[there] && capacity[here][there] - flow[here][there] > 0)
		{
			int ret = dfs(there, min(cost, capacity[here][there] - flow[here][there]));
			if(ret>0)
			{
				flow[here][there] += ret;
				flow[there][here] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int dinic()
{
	int totalFlow = 0;

	while (bfs())
	{
		memset(work, 0, sizeof(work));
		while (true)
		{
			int bp = dfs(S, INF);
			if (bp == 0) break;
			totalFlow += bp;
		}
	}

	return totalFlow;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		if (x == 0) continue;
		else if (x == 1)
		{
			adj[S].emplace_back(i);
			adj[i].emplace_back(S);
			capacity[S][i] = INF;
		}
		else if (x == 2) 
		{
			adj[T].emplace_back(i);
			adj[i].emplace_back(T);
			capacity[i][T] = INF;
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> capacity[i][j];
			if (i != j) adj[i].emplace_back(j);
		}
	}
		
	cout << dinic() << '\n';

	vector<bool> visited(MAX_N, false);
	visited[S] = false;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int here = q.front(); q.pop();
		for (auto there : adj[here])
		{
			if (!visited[there]&&capacity[here][there] - flow[here][there] > 0)
			{
				visited[there] = true;
				q.push(there);
			}
		}
	}

	for (int i = 1; i <= N; i++) if (visited[i]) cout << i << ' '; 
	cout << '\n';
	for (int i = 1; i <= N; i++) if (!visited[i]) cout << i << ' ';
	cout << '\n';
	

}