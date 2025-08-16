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

    int H,W,L;
    cin>>H>>W>>L;
    vvc grid(H,vc(W));
    for(auto &i : grid) for(auto &j : i) cin>>j;
    string str;
    cin>>str;

    vvvll dp(H,vvll(W,vll(L,-1)));

    int dx[8] = {0,0,1,-1,1,-1,-1,1};
    int dy[8] = {1,-1,0,0,1,1,-1,-1};
    auto solve = [&](auto &solve, int x, int y, int l)->ll{
        if(grid[x][y]!=str[l]) return 0LL;
        else{
            if(l==L-1) return 1LL;
        }
        ll &ret = dp[x][y][l];
        if(ret!=-1) return ret;
        ret = 0;

        for(int k=0;k<8;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(0<=nx&&nx<H && 0<=ny&&ny<W){
                ret += solve(solve,nx,ny,l+1);
            }
        }
        return ret;
    };

    ll ans = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans += solve(solve,i,j,0);
        }
    }
    /* for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<dp[i][j][0]<<' ';
        }
        cout<<'\n';
    } */
    cout<<ans;
}