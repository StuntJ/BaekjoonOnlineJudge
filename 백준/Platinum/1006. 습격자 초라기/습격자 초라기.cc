#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<ll,ll> pi;
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

    ll T;
    cin>>T;
    const ll INF = 1e9;
    while(T--)
    {
        ll N,W;
        cin>>N>>W;

        vector<vector<ll>> grid(2,vector<ll>(N));
        vector<vector<ll>> dp(N,vector<ll>(3,-1));
        for(auto &i : grid)
            for(auto &j : i) 
                cin>>j;

        auto initDp = [&]()->void{
            dp = vector<vector<ll>>(N,vector<ll>(3,-1));
        };

        auto solve = [&](auto &solve, ll here, ll stat, ll fstat)->ll{
            if(here==N){
                if(stat==fstat) return 0;
                else return INF;
            }
            if(here>N) return INF;
            ll &ret = dp[here][stat];
            if(ret!=-1) return ret;
            ret = INF;
            if(stat==0){
                if(grid[0][here]+grid[0][(here+1)%N]<=W && grid[1][here]+grid[1][(here+1)%N]<=W){
                    ret = min(ret,solve(solve,here+2,0,fstat)+2);
                }
                if(grid[0][here]+grid[0][(here+1)%N]<=W) ret = min(ret,solve(solve,here+1,2,fstat)+2);
                if(grid[1][here]+grid[1][(here+1)%N]<=W) ret = min(ret,solve(solve,here+1,1,fstat)+2);
                if(grid[0][here]+grid[1][here]<=W) ret = min(ret,solve(solve,here+1,0,fstat)+1);
                else ret = min(ret,solve(solve,here+1,0,fstat)+2); 
            }
            else if(stat==1){
                ret = min(ret,solve(solve,here+1,0,fstat)+1);
                if(grid[0][here]+grid[0][(here+1)%N]<=W) ret = min(ret,solve(solve,here+1,2,fstat)+1);
            }
            else{
                ret = min(ret,solve(solve,here+1,0,fstat)+1);
                if(grid[1][here]+grid[1][(here+1)%N]<=W) ret = min(ret,solve(solve,here+1,1,fstat)+1);
            }
            return ret;
        };

        ll ans = solve(solve,0,0,0);
        initDp();
        ans = min(ans,solve(solve,0,1,1));
        initDp();
        ans = min(ans,solve(solve,0,2,2));
        for(int i=0;i<2;i++){
            rotate(grid[i].begin(),grid[i].begin()+1,grid[i].end());
        }
        initDp();
        ans = min(ans,solve(solve,0,0,0));
        cout<<ans<<'\n';
    }
}