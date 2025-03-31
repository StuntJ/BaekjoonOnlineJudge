#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    
    int N,M,K;
    cin>>N>>M>>K;
    
    struct a_data
    {
        int here;
        int hereCost;
        int hereDist;
        
        bool operator < (const a_data &rhs) const{
            return hereDist>rhs.hereDist;
        }
    };
    vector<vector<a_data>> adj(N+1);
    
    for(int i=0;i<K;i++)
    {
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        
        adj[u].push_back({v,c,d});
    }
    
    for(int i=1;i<=N;i++)
        sort(adj[i].begin(),adj[i].end(),[](a_data &a, a_data &b)
             {
            return a.hereCost<b.hereCost;
        });
    
    const int INF = 987654321;
    priority_queue<a_data> pq;
    vector<vector<int>> dp(N+1,vector<int>(M+1,INF));
    dp[1][0] = 0;
    pq.push({1,0,0});
    
    while(!pq.empty())
    {
        int here = pq.top().here;
        int hereCost = pq.top().hereCost;
        int hereDist = pq.top().hereDist;
        pq.pop();
        
        if(dp[here][hereCost]<hereDist) continue;
        
        for(auto p : adj[here])
        {
            int next = p.here;
            int nextCost = hereCost + p.hereCost;
            int nextDist = hereDist + p.hereDist;
            if(nextCost>M) break;
            if(dp[next][nextCost]<=nextDist) continue;
            
            for(int i=nextCost;i<=M;i++)
            {
                if(dp[next][i]<=nextDist) break;
                dp[next][i] = nextDist;
            }
            pq.push({next,nextCost,nextDist});
        }
    }
    
    int res = *min_element(dp[N].begin(), dp[N].end()); //10000
    if(res==INF) cout<<"Poor KCM";
    else cout<<res;
}
