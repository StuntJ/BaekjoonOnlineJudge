#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct v_data{
    int move;
    int minX;
    int maxX;
    ll t;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int R,D;
    int M;

    cin>>N;
    cin>>R>>D;
    cin>>M;

    vector<v_data> edgeset;
    for(int i=0;i<M;i++){
        int h,e1,e2;
        ll t;
        cin>>h>>t>>e1>>e2;

        v_data data1,data2;
        data1.minX = e1;
        data1.maxX = N-(h-e1);
        data1.t = t;
        data1.move = e2-e1;
        data2.minX = e2;
        data2.maxX = N-(h-e2);
        data2.t = t;
        data2.move = e1-e2;
        edgeset.emplace_back(data1);
        edgeset.emplace_back(data2);
    }

    vector<vector<pair<ll,int>>> adj(N+1);

    for(int i=1;i<=N;i++){
        for(auto data : edgeset){
            if(data.minX<=i && i<=data.maxX){
                adj[i].emplace_back(make_pair(data.t,i+data.move));
            }
        }
    }

    const ll INF = 1e15;
    vector<ll> dist(N+1,INF);
    dist[R] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,R});
    
    while(!pq.empty()){
        int hereDist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(hereDist>dist[here]) continue;

        for(auto n : adj[here]){
            int nextDist = hereDist + n.first;
            int next = n.second;
            if(nextDist<dist[next]){
                dist[next] = nextDist;
                pq.push({-nextDist,next});
            }
        }
    }

    cout<<(dist[D]==INF ? -1 : dist[D]);
}