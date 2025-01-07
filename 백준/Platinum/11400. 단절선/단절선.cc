#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> discovered;
vector<pair<int, int>> cutLine;
int vertexCounter;

int isCutLine(int src, int parent = -1)
{
	int ret = discovered[src] = vertexCounter++;
	for (auto there : adj[src])
	{
		if (there == parent) continue;
		if (discovered[there] == -1)
		{
			int subtree = isCutLine(there, src);

			if (subtree > discovered[src]) cutLine.push_back(make_pair(src, there));
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	adj.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int A, B;
		cin >> A >> B;

		adj[A].emplace_back(B);
		adj[B].emplace_back(A);
	}

	discovered.assign(V + 1, -1);
	vertexCounter = 0;

	isCutLine(1);

	for (int i = 0; i < cutLine.size(); i++)
		if (cutLine[i].first > cutLine[i].second) swap(cutLine[i].first, cutLine[i].second);
	
	sort(cutLine.begin(), cutLine.end());
	cout << cutLine.size() << '\n';
	for (auto ans : cutLine) cout << ans.first << ' ' << ans.second << '\n';
	
}