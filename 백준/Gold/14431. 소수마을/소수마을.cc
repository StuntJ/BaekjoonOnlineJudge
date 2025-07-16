#include <bits/stdc++.h>

using namespace std;

const int lim = 30001;
unordered_set<int> prime(){
    vector<bool> isPrime(lim,1);
    isPrime[0] = isPrime[1] = false;

    for(int i=2;i*i<=lim-1;i++){
        for(int j=i*i;j<=lim-1;j+=i)
            isPrime[j] = false;
    }

    unordered_set<int> st;
    for(int i=2;i<lim;i++)
        if(isPrime[i]) 
            st.insert(i);
    
    /* for(int i=2;i<lim;i++)
        if(isPrime[i])
            cout<<i<<' '; */
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> st = prime();
 
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<pair<int,int>> vp;
    //0->1
    vp.push_back({x1,y1});
    vp.push_back({x2,y2});

    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        vp.push_back({x,y});
    }

    int sz =vp.size();
    vector<vector<pair<int,int>>> adj(sz);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            int dist = hypot(vp[i].first-vp[j].first,vp[i].second-vp[j].second);
            if(st.find(dist)!=st.end()){
                adj[i].emplace_back(make_pair(dist,j));
                adj[j].emplace_back(make_pair(dist,i));
            }
        }
    }

    const int INF = 1e9;
    vector<int> dist(sz,INF);
    dist[0] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int here = pq.top().second;
        int hereDist = -pq.top().first;
        pq.pop();

        if(dist[here]<hereDist) continue;

        for(auto n : adj[here]){
            int next = n.second;
            int nextDist = hereDist + n.first;
            if(nextDist<dist[next]){
                pq.push({-nextDist,next});
                dist[next] = nextDist;
            }
        }
    }

    cout<<(dist[1]!=INF ? dist[1] : -1);
}