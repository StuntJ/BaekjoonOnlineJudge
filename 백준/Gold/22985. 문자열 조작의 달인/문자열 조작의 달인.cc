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

const ll mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,M;
    cin>>N>>M;

    M = min(M,25*N);

    vvvll dp(N+1,vvll(M+1,vll(2)));
    string str;
    cin>>str;

    if(str[0]=='z') dp[0][M][1] = 1;
    else dp[0][M][0] = 1;

    for(int i=0;i<N;i++){
        int change = 'z'-str[i];
        for(int j=0;j<=M;j++){
            for(int k=0;k<change;k++){
                if(j>=k){
                    dp[i+1][j-k][0] += dp[i][j][0];
                    dp[i+1][j-k][0] %= mod;
                    dp[i+1][j-k][1] += dp[i][j][1];
                    dp[i+1][j-k][1] %= mod;
                }
            }
            if(j>=change){
                dp[i+1][j-change][1] += dp[i][j][0];
                dp[i+1][j-change][1] %= mod;
                dp[i+1][j-change][1] += dp[i][j][1];    
                dp[i+1][j-change][1] %= mod;
            }
        }
    }

    ll ans = dp[N][0][0];
    for(int i=0;i<=M;i++){
        ans += dp[N][i][1];
        ans %= mod;
    }

    cout<<ans;
}