#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define INF 2000000001

using namespace std;
vector<vector<int>> adj;
vector<set<int>> presccAdj;
vector<vector<int>> sccAdj;
vector<int> discovered;
vector<int> sccId;
vector<bool> sccRestaurant;
vector<int> sccVertexVal;
vector<int> cache;
stack<int> st;
int sccCount,vertexCount;
int N,M;
int S,P;
int S_area;

int dpDfs(int here)
{
    int &ret = cache[here];
    if(ret!=-1) return ret;
    if(here==S_area) return ret = sccVertexVal[here];
    ret = -INF;

    for(int i=0;i<sccAdj[here].size();i++)
    {
        int there = sccAdj[here][i];
        int nextVal = dpDfs(there);
        ret = max(ret,sccVertexVal[here]+nextVal);
    }

    if(ret<0) ret = -INF;

    return ret;
}

int solve()
{
    cache.assign(sccCount,-1);
    S_area = sccId[S];
    int ret = -INF;
    for(int i=0;i<sccCount;i++)
    {
        if(sccRestaurant[i])
            ret = max(ret,dpDfs(i));
    }
    return ret;
}

int scc(int here)
{
    int ret = discovered[here] = vertexCount++;
    st.push(here);

    for(int i=0;i<adj[here].size();i++)
    {
        int there = adj[here][i];
        if(discovered[there]==-1)
            ret = min(ret,scc(there));
        else if(sccId[there]==-1)
            ret = min(ret,discovered[there]);
    }

    if(ret == discovered[here])
    {
        while(true)
        {
            int t = st.top();
            st.pop();
            sccId[t] = sccCount;
            if(t==here) break;
        }
        sccCount++;
    }
    return ret;
}

void tarjanScc()
{
    sccCount = vertexCount = 0;
    discovered = sccId = vector<int>(N+1,-1);

    for(int i=1;i<=N;i++)
        if(discovered[i]==-1)
            scc(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    adj = vector<vector<int>>(N+1);

    for(int i=0;i<M;i++)
    {
        int start,finish;
        cin>>start>>finish;

        adj[start].emplace_back(finish);
    }
    tarjanScc();
    presccAdj.resize(sccCount);
    sccAdj.resize(sccCount);

    /*for(int i=1;i<=N;i++)
        cout<<sccId[i]<<' ';
    cout<<'\n';*/

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(sccId[i]!=sccId[adj[i][j]])
            {
                presccAdj[sccId[i]].insert(sccId[adj[i][j]]);
            }
        }
    }

    for(int i=0;i<sccCount;i++)
    {
        set<int>::iterator iter;
        for(iter = presccAdj[i].begin();iter!=presccAdj[i].end();iter++)
            sccAdj[*iter].emplace_back(i);
    }

    sccRestaurant = vector<bool>(sccCount,false);
    sccVertexVal = vector<int>(sccCount,0);

    for(int i=1;i<=N;i++)
    {
        int val;
        cin>>val;
        sccVertexVal[sccId[i]]+=val;
    }

    cin>>S>>P;

    for(int i=0;i<P;i++)
    {
        int val;
        cin>>val;
        sccRestaurant[sccId[val]] = true;
    }

    /*for(int i=0;i<sccCount;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<sccAdj[i].size();j++)
            cout<<sccAdj[i][j]<<' ';
        cout<<'\n';
    }*/

    cout<<solve();
}
