#include <bits/stdc++.h>

using namespace std;

struct disjointSet
{
    int floodNum;
    vector<int> parent,rank;
    vector<int> capacity,rain,number;
    vector<bool> flood;

    disjointSet(int n) : parent(n+1), rank(n+1,1), capacity(n+1), rain(n+1),flood(n+1,false),number(n+1,1)
    {
        floodNum = 0;
        for(int i=1;i<=n;i++)
            cin>>capacity[i];
        for(int i=1;i<=n;i++)
        {
            cin>>rain[i];
            if(capacity[i]<rain[i])
            {
                flood[i] = true;
                floodNum++;
            }

        }

        for(int i=1;i<=n;i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(rank[u]>rank[v]) swap(u,v);
        parent[u] = v;
        capacity[v] += capacity[u];
        rain[v] += rain[u];
        if(capacity[v]<rain[v]) //flood
        {
            if(!flood[v]) floodNum+=number[v];
            if(!flood[u]) floodNum+=number[u];

            number[v] += number[u];
            flood[v] = true;
        }
        else //not flood
        {
            if(flood[v]) floodNum-=number[v];
            if(flood[u]) floodNum-=number[u];

            number[v] += number[u];
            flood[v] = false;
        }

        if(rank[u]==rank[v]) rank[v]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    disjointSet d_set(N);
    //cout<<d_set.floodNum<<'\n';

    for(int i=0;i<M;i++)
    {
        int order;
        cin>>order;

        if(order==1)
        {
            int x,y;
            cin>>x>>y;
            d_set.merge(x,y);
        }
        else cout<<d_set.floodNum<<'\n';
    }
}
