#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> cache;

int TSP(int here,int visited)
{
    if(visited==(1<<N)-1) return adj[here][0];
    int &ret = cache[here][visited];
    if(ret!=-1) return ret;
    ret = INF;

    for(int i=0;i<N;i++)
    {
        if(adj[here][i]==INF) continue;
        if(!(visited&(1<<i)))
        {
            ret = min(ret,adj[here][i]+TSP(i,visited|(1<<i)));
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    adj.resize(N+1,vector<int>(N+1));
    cache.assign(N+1,vector<int>(1<<N,-1));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>adj[i][j];
            if(i!=j&&adj[i][j]==0) adj[i][j] = INF;
        }
    }

    cout<<TSP(0,1);
}
