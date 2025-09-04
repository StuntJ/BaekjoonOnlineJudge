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
    N*=2;

    vi v(N);
    for(auto &i : v) cin>>i;

    vvi adj(N);
    vb visited(N);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(__builtin_popcount(v[i]^v[j])<=1){
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    int idx = 0;
    vvi element;
    auto dfs = [&](auto &dfs, int here)->int{
        element[idx].push_back(v[here]);
        visited[here] = true;
        int ret = 1;
        for(auto next : adj[here]){
            if(!visited[next]){
                ret += dfs(dfs,next);
            }
        }
        return ret;
    };

    vi sz;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            vi temp;
            element.push_back(temp);
            sz.push_back(dfs(dfs,i));
            idx++;
        }     
    }

    int X = sz.size();
    vvi dp(X+1,vi(N+1));
    dp[0][0] = 1;
    for(int i=0;i<X;i++){
        for(int j=N/2;j>=0;j--){
            if(dp[i][j]) dp[i+1][j] = 1;
            if(j-sz[i]>=0 && dp[i][j-sz[i]]) dp[i+1][j] = 1;
        }
    }
    
    bool flag = false;
    int start = 0;
    for(int i=0;i<=X;i++){
        if(dp[i][N/2]){
            flag = true;
            start = i;
            break;
        }
    }
    if(!flag){
        cout<<-1;
        return 0;
    }

    int y = N/2;
    vector<int> A,B;
    while(y>0){
        if(dp[start-1][y-sz[start-1]]){
            y = y-sz[start-1]; 
            A.push_back(start-1);
            start--;
        }
        else{
            start--;
        } 
    }

    vector<int> x;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<element[A[i]].size();j++)
        {
            x.push_back(element[A[i]][j]);
        }
    }
    vector<int> ret;
    for(int i=0;i<v.size();i++){
        int com = v[i];
        bool flag = false;
        for(int j=0;j<x.size();j++){
            if(com==x[j]){
                flag = true;
                break;
            }
        }
        if(!flag) ret.push_back(com);
    } 
    for(auto &i : x) cout<<i<<' ';
    cout<<'\n';
    for(auto &i : ret) cout<<i<<' ';
}