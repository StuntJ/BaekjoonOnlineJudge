#include <bits/stdc++.h>

using namespace std;

struct v_data
{
    int x;
    int y;
    int V;
    int pic;
};

vector<vector<int>> adj;
vector<v_data> info;

bool dfs(int src, vector<bool> &visited)
{
    visited[src] = true;

    if(src==0) return true;

    bool isThere = false;
    for(auto next :adj[src])
    {
        if(!visited[next])
        {
            if(dfs(next,visited)) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K,T;
    cin>>N>>K>>T;

    adj.resize(N+1);
    info.resize(N+1);

    int xp,yp,vp;
    cin>>xp>>yp>>vp;
    info[0] = {xp,yp,vp,0};

    queue<int> start;
    for(int i=1;i<=N;i++)
    {
        int xi,yi,vi,isPic;
        cin>>xi>>yi>>vi>>isPic;

        info[i] = {xi,yi,vi,isPic};
        if(isPic) start.push(i);
    }

    for(int i=0;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(abs(info[i].V-info[j].V)<=T)
            {
                double dist = hypot((double)info[i].x-info[j].x,(double)info[i].y-info[j].y);
                if(dist<=(double)K)
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }

        }
    }

    int cnt = 0;
    while(!start.empty())
    {
        vector<bool> visited(N+1,false);
        if(dfs(start.front(),visited))
        {
            cnt++;
            cout<<start.front()<<' ';
        }
        start.pop();
    }
    if(cnt==0) cout<<0;
}
