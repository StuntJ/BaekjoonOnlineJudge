#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vvpi adj(N+1);

    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    auto getFar = [&](auto &getFar, int here, vector<bool> &visited)->pair<int,ll>{
        visited[here] = true;
        
        pair<int,ll> ret = {here,0LL};
        for(auto n : adj[here]){
            int next = n.first;
            if(visited[next]) continue;
            pair<int,ll> temp = getFar(getFar,next,visited);
            ll tempDist = n.second + temp.second;
            if(tempDist>ret.second){
                ret = {temp.first,tempDist};
            }

        }
        return ret;
    };

    vb visited(N+1);
    int u = getFar(getFar,1,visited).first;
    visited = vb(N+1);
    int v = getFar(getFar,u,visited).first;

    visited = vb(N+1);
    visited[u] = true;
    int s = 0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            s = i;
            break;
        }
    }
    int y = getFar(getFar,s,visited).first;
    visited = vb(N+1);
    visited[u] = true;
    ll res1 = getFar(getFar,y,visited).second;

    visited = vb(N+1);
    visited[v] = true;
    s = 0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            s = i;
            break;
        }
    }
    y = getFar(getFar,s,visited).first;
    visited = vb(N+1);
    visited[v] = true;
    ll res2 = getFar(getFar,y,visited).second;
    //cout<<res1<<' '<<res2<<'\n';
    cout<<max(res1,res2);
}