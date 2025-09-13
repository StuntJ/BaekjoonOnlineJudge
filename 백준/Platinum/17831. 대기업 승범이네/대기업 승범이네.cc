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

    vvi adj(N+1);
    for(int i=2;i<=N;i++){
        int x;
        cin>>x;

        adj[i].emplace_back(x);
        adj[x].emplace_back(i);
    }
    vll v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    vvll dp(N+1,vll(2));

    const ll INF = 2000000000;
    auto solve = [&](auto &solve, int here, int parent)->void{
        for(int next : adj[here]){
            if(parent==next) continue; 
            solve(solve,next,here);
        }

        int mxidx = -1;
        ll bp = -INF;
        for(int next : adj[here]){
            if(parent==next) continue;
            dp[here][0] += max(dp[next][0],dp[next][1]);
            ll temp = v[here]*v[next]+dp[next][0]-max(dp[next][0],dp[next][1]);
            if(temp>bp){
                bp = temp;
                mxidx = next;
            }
        }

        for(int next : adj[here]){
            if(parent==next) continue;
            dp[here][1] += max(dp[next][0], dp[next][1]);
        }
        dp[here][1] += bp;
    };

    solve(solve,1,-1);
    cout<<max(dp[1][0],dp[1][1]);
}