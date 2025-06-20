#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n,m,t;
        cin>>n>>m>>t;

        int s,g,h;
        cin>>s>>g>>h;

        vector<vector<int>> adj(n+1,vector<int>(n+1));
        while(m--){
            int a,b,d;
            cin>>a>>b>>d;
            adj[a][b] = d;
            adj[b][a] = d;
        }

        const int INF = 1e+9;
        auto dijkstra = [&](int st)->vector<int>{
            vector<int> dist(n+1, INF);
            priority_queue<pair<int,int>> pq;
            pq.push({0,st});
            dist[st] = 0;

            while(!pq.empty()){
                int here = pq.top().second;
                int hereDist = -pq.top().first;
                pq.pop();

                if(dist[here]<hereDist) continue;

                for(int next = 1;next<=n;next++){
                    if(!adj[here][next]) continue;
                    int nextDist = hereDist + adj[here][next];
                    if(dist[next]>nextDist){
                        dist[next] = nextDist;
                        pq.push({-nextDist,next});
                    }
                }
            }
            return dist;
        };
        vector<int> nd(t);
        for(auto &i : nd) cin>>i;
        vector<int> totDist = dijkstra(s);
        vector<int> gDist = dijkstra(g);
        vector<int> hDist = dijkstra(h);
        vector<int> ans;
        /* for(auto i : totDist) cout<<i<<' ';
        cout<<'\n';
        for(auto i : gDist) cout<<i<<' ';
        cout<<'\n';
        for(auto i : hDist) cout<<i<<' ';
        cout<<'\n'; */
        for(auto i : nd){
            if(gDist[i]<hDist[i]){
                int p1 = gDist[i];
                int p2 = totDist[h];
                int p3 = adj[g][h];

                if(p1+p2+p3==totDist[i]) ans.push_back(i);
            }
            else{
                int p1 = hDist[i];
                int p2 = totDist[g];
                int p3 = adj[g][h];

                if(p1+p2+p3==totDist[i]) ans.push_back(i);
            }
        }
        // cout<<"size : "<<ans.size()<<'\n';
        sort(ans.begin(),ans.end());
        for(auto i : ans) cout<<i<<' ';
        cout<<'\n';
    }
}