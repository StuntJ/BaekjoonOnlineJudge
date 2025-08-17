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

    vi a(N);
    vvi dp(N,vi(2));
    for(auto &i : a) cin>>i;

    int ans = a[0];
    for(int i=0;i<N;i++){
        dp[i][0] = dp[i][1] = a[i];
        if(i==0) continue;
        dp[i][0] = max(dp[i-1][0]+a[i],dp[i][0]);
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]+a[i]);
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<'\n';
}