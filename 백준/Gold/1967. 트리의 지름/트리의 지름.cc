#include <iostream>
#include <vector>
#define START_VERTEX 1

using namespace std;

vector<vector<pair<int,int>>> tree; //value,vertex
vector<bool> visited;

int rtLongestPath(int here,int &leafToleafMax)
{
    visited[here] = true;
    int ret = 0;
    int secondaryLength = -1;
    int children = tree[here].size();
    for(int i=0;i<children;i++)
    {
        int nextCost = tree[here][i].first;
        int there = tree[here][i].second;
        if(visited[there]) continue;
        int comp = nextCost+rtLongestPath(there,leafToleafMax);

        if(ret<comp)
        {
            secondaryLength = ret;
            ret = comp;
        }
        else
            secondaryLength = max(secondaryLength,comp);

    }
    if(children>=2)
        leafToleafMax = max(leafToleafMax,ret+secondaryLength);

    if(here==START_VERTEX) return max(leafToleafMax,ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin>>V;

    tree.resize(V+1);
    visited.assign(V+1,false);

    for(int i=0;i<V-1;i++)
    {
        int start,finish,cost;
        cin>>start>>finish>>cost;

        tree[start].emplace_back(make_pair(cost,finish));
    }
    int leafToleafMax = 0;
    cout<<rtLongestPath(START_VERTEX,leafToleafMax);
}
