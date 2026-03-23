#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

void solve(){
    int N,M;
    cin>>N>>M;

    vector<vector<char>> grid(N+1,vector<char>(M+1));
    vector<vector<int>> G(N+1,vector<int>(M+1)), B(N+1,vector<int>(M+1));
    vector<vector<int>> Dif(N+1,vector<int>(M+1));
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>grid[i][j];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(grid[i][j]=='G' && grid[i][j-1]=='G'){
                G[i][j] = G[i][j-1]+1;
            }
            else if (grid[i][j]=='B' && grid[i][j-1]=='B'){
                B[i][j] = B[i][j-1]+1;
            }
            else{
                if(grid[i][j]=='G'){
                    G[i][j] = 1;
                }
                else{
                    B[i][j] = 1;
                }
            }
        }
    }

    for(int j=2;j<=M;j++){
        for(int i=1;i<=N;i++){
            if(grid[i][j]==grid[i][j-1])
                Dif[i][j] = Dif[i-1][j] + 1;
            else Dif[i][j] = 0;
        }
    }

    vector<vector<int>> dp(N+1,vector<int>(M+1));
    for(int j=1;j<=M;j++) dp[1][j] = 1;
    for(int i=1;i<=N;i++) dp[i][1] = 1;

    for(int i=2;i<=N;i++){
        for(int j=2;j<=M;j++){
            dp[i][j] = max(1,min({dp[i-1][j-1]+1,(grid[i][j]=='B' ? B[i][j] : G[i][j]), Dif[i][j]}));
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            ans = max(ans,dp[i][j]);
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans*ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}