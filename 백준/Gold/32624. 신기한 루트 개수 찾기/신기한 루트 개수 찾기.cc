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

    int N,A,B;
    cin>>N>>A>>B;
    
    vvi adj(N+1);
    for(int i=0;i<N-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vb visited(N+1);
    auto dfs1 = [&](auto &dfs1, int here)->bool{
        visited[here] = true;
        if(here==B) return true;
        bool ret = false;
        for(auto next : adj[here]){
            if(!visited[next])
                ret |= dfs1(dfs1,next);
        }
        return ret;
    };

    vb visited2(N+1);
    auto dfs2 = [&](auto &dfs2, int here)->int{
        visited2[here] = true;
        int ret = 1;
        for(auto next : adj[here]){
            if(!visited2[next])
                ret += dfs2(dfs2,next);
        }
        return ret;
    };

    int ansP;
    
    visited2[A] = true;
    visited2[B] = true;
    visited[A] = true;
    for(auto path : adj[A]){
        if(path==B){
            cout<<0;
            return 0;
        }
        bool res = dfs1(dfs1,path);
        if(res) ansP = path;
        else visited2[path] = true;
    }
    cout<<dfs2(dfs2,ansP);
}