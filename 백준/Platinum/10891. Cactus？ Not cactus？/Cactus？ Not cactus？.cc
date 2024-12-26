#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<vector<pair<int, int>>> bccdata;
vector<int> discovered;
stack<pair<int, int>> st;
int vertexCounter;

int bcc(int src,int parent = -1)
{
	int ret = discovered[src] = vertexCounter++;
	for (int there : adj[src])
	{
		if (there == parent) continue;
		if (discovered[src] > discovered[there]) st.push(make_pair(src, there));
		if (discovered[there] == -1)
		{
			int subtree = bcc(there, src);
			ret = min(ret, subtree);

			if (subtree >= discovered[src])
			{
				vector<pair<int, int>> temp;
				while (!st.empty())
				{
					int x, y;
					tie(x, y) = st.top();
					st.pop();
					temp.push_back({ x,y });
					if (min(x, y) == min(src, there) && max(x, y) == max(src, there)) break;
				}
				bccdata.push_back(temp);
			}
		}
		else ret = min(ret, discovered[there]);
	}
	return ret;
}

vector<vector<pair<int, int>>> get_bcc()
{
	vertexCounter = 0;
	discovered = vector<int>(V + 1, -1);
	for (int i = 1; i <= V; i++)
		if (discovered[i] == -1) bcc(i);
	return bccdata;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V >> E;
	adj.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<vector<pair<int, int>>> b_data = get_bcc();
	vector<int> count(V + 1, 0);

	for (int i = 0; i < b_data.size(); i++)
	{
		set<int> num;
		if (b_data[i].size() < 3) continue;
		for (auto k : b_data[i])
		{
			num.insert(k.first);
			num.insert(k.second);
		}
		if (num.size() == b_data[i].size())
		{
			for (auto next : num)
				count[next]++;
		}
		else
		{
			cout << "Not cactus";
			return 0;
		}
	}
	/*for (int i = 1; i <= V; i++) cout << count[i] << ' ';
	cout << '\n';*/

	for(int i=1;i<=V;i++) 
		if (count[i] >= 2)
		{
			cout << "Not cactus";
			return 0;
		}

	cout << "Cactus";
}