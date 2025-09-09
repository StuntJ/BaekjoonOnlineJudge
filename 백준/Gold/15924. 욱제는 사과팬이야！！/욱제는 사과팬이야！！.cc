#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<char>> grid(N+1,vector<char>(M+1));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<ll>> dp(N+1,vector<ll>(M+1));

    dp[N][M] = 1LL;
    for(int i=N;i>0;i--){
        for(int j=M;j>0;j--){
            if(grid[i-1][j]=='S'||grid[i-1][j]=='B'){
                dp[i-1][j] = (dp[i][j] + dp[i-1][j])%mod;
            }
            if(grid[i][j-1]=='E'||grid[i][j-1]=='B'){
                dp[i][j-1] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }   

    ll ans = 0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            ans = (ans+dp[i][j])%mod;
            
    cout<<ans;
}