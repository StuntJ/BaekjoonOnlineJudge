#include <bits/stdc++.h>

using namespace std;

bool isBipartiteGraph(int src, vector<vector<int>> &adj,vector<int> &info)
{
    int srcnum = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(src,srcnum));
    info[src] = srcnum%2;

    while(!q.empty())
    {
        int here = q.front().first;
        int herenum = q.front().second;
        q.pop();

        for(auto there : adj[here])
        {
            if(info[here]==info[there]) return false;
            else if(info[there]==-1)
            {
                info[there] = (herenum+1)%2;
                q.push(make_pair(there,herenum+1));
            }
            else continue;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin>>K;

    for(int t=0;t<K;t++)
    {
        int V,E;
        cin>>V>>E;

        vector<vector<int>> adj(V+1);
        vector<int> info(V+1,-1);

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        bool flag = true;

        for(int i=1;i<=V;i++)
        {
            if(info[i]==-1)
            {
                if(!isBipartiteGraph(i,adj,info))
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
