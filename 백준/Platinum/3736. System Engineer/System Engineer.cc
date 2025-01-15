#include <bits/stdc++.h>

using namespace std;

//직업의 인덱스 서버의 인덱스 모두 0부터 시작한다.
int N;
vector<vector<int>> adj;
vector<int> aMatch, bMatch;
vector<bool> used;
vector<int> level;
vector<bool> visited;

void bfs()
{
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		if (!used[i])
		{
			level[i] = 0;
			q.push(i);
		}
		else level[i] = -1;
	}

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (auto there : adj[here])
		{
			if (bMatch[there] != -1 && level[bMatch[there]] == -1)
			{
				level[bMatch[there]] = level[here] + 1;
				q.push(bMatch[there]);
			}
		}
	}
}

int dfs(int a)
{
	if (visited[a]) return false;
	visited[a] = true;

	for (int b : adj[a])
	{
		if (bMatch[b] == -1 || (!visited[bMatch[b]] && level[bMatch[b]] == level[a] + 1 && dfs(bMatch[b])))
		{
			used[a] = true;
			aMatch[a] = b;
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}

int Hopcroft_Karp()
{
	int totalMatch = 0;
	aMatch = bMatch = vector<int>(N, -1);
	used = vector<bool>(N, false);
	level = vector<int>(N, -1);

	while (true)
	{
		bfs();
		int flow = 0;
		for (int i = 0; i < N; i++)
		{
			visited = vector<bool>(N, false);
			if (!used[i] && dfs(i)) flow++;
		}
		if (flow == 0) break;
		totalMatch += flow;
	}
	return totalMatch;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N)
	{
		adj = vector<vector<int>>(N);

		for (int i = 0; i < N; i++)
		{
			string job, nr;
			char bp;
			cin >> job >> bp >> nr;
			int jb = stoi(job);
			int num = stoi(nr);
			for (int j = 0; j < num; j++)
			{
				int server;
				cin >> server;
				adj[jb].emplace_back(server - N);
			}
		}
		cout << Hopcroft_Karp() << '\n';
	}
}