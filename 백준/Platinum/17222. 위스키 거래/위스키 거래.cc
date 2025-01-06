#include <bits/stdc++.h>
#define S 0
#define T 101
#define T_CAN_GET 10000001
#define MAX_V 102

using namespace std;

vector<int> canGet;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink)
{
	int totalFlow = 0;
	while (true)
	{
		vector<int> parent(T + 1, -1);
		queue<int> q;
		q.push(source);
		parent[source] = source;
		while (!q.empty() && parent[sink] == -1)
		{
			int here = q.front();
			q.pop();
			for (int there = 0; there < MAX_V; there++)
			{
				if (capacity[here][there] > flow[here][there] && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == -1) break;
		int amount = T_CAN_GET;
		for (int i = sink; i != source; i = parent[i])
			amount = min(amount, capacity[parent[i]][i] - flow[parent[i]][i]);

		for (int i = sink; i != source; i = parent[i])
		{
			flow[parent[i]][i] += amount;
			flow[i][parent[i]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	canGet.assign(N + M + 1, 0);
	for (int i = 1; i <= N + M; i++)
	{
		int x;
		cin >> x;
		canGet[i] = x;
	}

	for (int i = N + 1; i <= N + M; i++)
	{
		int num;
		cin >> num;
		while (num--)
		{
			int x;
			cin >> x;
			capacity[i][x] = canGet[x];
		}
		capacity[S][i] = canGet[i];
	}

	for (int i = 1; i <= N; i++)
		capacity[i][T] = T_CAN_GET;
		
	cout << networkFlow(S, T);

}