#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> discovered;
vector<set<int>> bccRes;
vector<int> oneOfbcc;
stack<pair<int, int>> st;
int vertexCounter, bccCounter;

int bcc(int src, int parent = -1)
{
	int ret = discovered[src] = vertexCounter++;
	for (auto there : adj[src])
	{
		if (there == parent) continue;
		if (discovered[src] > discovered[there])
			st.push(make_pair(src, there));
		if (discovered[there] == -1)
		{
			int subtree = bcc(there, src);
			ret = min(subtree, ret);

			if (subtree >= discovered[src])
			{
				oneOfbcc.emplace_back(src);
				while (!st.empty())
				{
					int x, y;
					tie(x, y) = st.top();
					st.pop();
					bccRes[x].insert(bccCounter);
					bccRes[y].insert(bccCounter);
					if (min(x, y) == min(src, there) && max(x, y) == max(src, there)) break;
				}
				bccCounter++;
			}
		}
		else
			ret = min(ret, discovered[there]);
	}
	return ret;
}

void make_bcc()
{
	vertexCounter = bccCounter = 0;
	discovered = vector<int>(V + 1, -1);
	bccRes = vector<set<int>>(V + 1);
	oneOfbcc.clear();

	for (int i = 1; i <= V; i++)
		if (discovered[i] == -1)
			bcc(i);
}

bool isOdd;
int maximumCounter;
vector<int> point;
void dfs(int bccCounter, int src, int parent = -1)
{
	point.emplace_back(src);
	for (auto there : adj[src])
	{
		if (there == parent) continue;
		if (bccRes[there].find(bccCounter) != bccRes[there].end())
		{
			if (discovered[there] > vertexCounter)
			{
				if ((discovered[src] - discovered[there]) % 2 == 0)
					isOdd = true;
			}
			else if(discovered[there]<=vertexCounter)
			{
				discovered[there] = discovered[src] + 1;
				maximumCounter = max(maximumCounter, discovered[there]);
				dfs(bccCounter, there, src);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		
		cin >> V >> E;
		
		adj = vector<vector<int>>(V + 1);
		vector<bool> chk(V + 1, false);

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}

		make_bcc();

		vertexCounter = -1;
		discovered = vector<int>(V + 1, -1);
		for (int i = 0; i < bccCounter; i++)
		{
			point.clear();
			isOdd = false;
			discovered[oneOfbcc[i]] = vertexCounter + 1;
			dfs(i, oneOfbcc[i]);
			vertexCounter = maximumCounter;

			if (isOdd) for (auto i : point) chk[i] = true;
		}

		int cnt = 0;
		for (int i = 1; i <= V; i++)
			if (chk[i]) cnt++;
		
		cout << cnt << '\n';
	}
}