#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,R,D,x,y;
    cin>>N>>R>>D>>x>>y;

    vector<pair<int,int>> v(N);
    for(auto &i : v) cin>>i.first>>i.second;
    const int INF = 1e9;
    vector<vector<int>> adj(N);

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            double dist = hypot((double)v[i].first-v[j].first,(double)v[i].second-v[j].second);
            if(dist<=R){
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    queue<int> q;
    vector<int> d(N,-1);
    for(int i=0;i<N;i++){
        double dist = hypot((double)v[i].first-x,(double)v[i].second-y);
        if(dist<=R){
            q.push(i);
            d[i] = 0;
        }
    }
    
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : adj[here]){
            if(d[next]==-1){
                d[next] = d[here]+1;
                q.push(next);
            }
        }
    }

    //vector<double> strength(N);
    double st = 0;
    for(int i=0;i<N;i++){
        if(d[i]==-1) continue;
        st += pow(0.5,d[i]) * D;
    }
    cout<<fixed;
    cout.precision(2);
    cout<<st;
}