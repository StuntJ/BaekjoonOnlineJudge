#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<set<int>> bccRes;
stack<pair<int, int>> st;
int vertexCounter, bccCounter;
int V, E;

int bcc(int src, int parent = -1)
{
	int ret = discovered[src] = vertexCounter++;
	for (auto next : adj[src])
	{
		if (next != parent)
		{
			if (discovered[src] > discovered[next]) // 역행간선이거나 방문하지 않은 간선이면
				st.push(make_pair(src, next));
			if (discovered[next] == -1) //방문하지 않은 간선 (트리간선) 이면
			{
				int subtree = bcc(next, src);
				ret = min(ret, subtree);

				if (subtree >= discovered[src])
				{
					while (!st.empty())
					{
						int x, y;
						tie(x, y) = st.top();
						st.pop();
						bccRes[x].insert(bccCounter);
						bccRes[y].insert(bccCounter);
						if (min(x, y) == min(src, next) && max(x, y) == max(src, next)) break;
					}
					++bccCounter;
				}
			}
			else //역행간선이면
				ret = min(ret, discovered[next]);
		}
	}
	return ret;
}

int get_bcc()
{
	vertexCounter = bccCounter = 0;
	discovered = vector<int>(V, -1);
	bccRes = vector<set<int>>(V);
	int cnt = 0;
	for (int i = 0; i < V; i++)
	{
		if (discovered[i] == -1)
		{
			cnt++;
			bcc(i);
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> V >> E;
		if (V == 0) return 0;
		adj = vector<vector<int>>(V);
		vector<bool> chk(V);
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			chk[a] = true;
			chk[b] = true;
		}

		int tot = get_bcc();
		int ans = 0;

		for (int i = 0; i < V; i++)
		{
			if (!chk[i]) ans = max(ans, tot - 1);
			else ans = max(ans, tot + (int)bccRes[i].size() - 1);
		}
		cout << ans << '\n';
	}
}