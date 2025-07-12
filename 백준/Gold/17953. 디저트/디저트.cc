#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> grid(M+1,vector<int>(N+1));
    vector<vector<int>> dp(M+1,vector<int>(N+1));
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            cin>>grid[i][j];

    for(int j=1;j<=N;j++){
        for(int i=1;i<=M;i++){
            for(int k=1;k<=M;k++){
                if(i==k && j!=1) dp[i][j] = max(dp[i][j], dp[k][j-1] + grid[i][j]/2);
                else dp[i][j] = max(dp[i][j],dp[k][j-1] + grid[i][j]);
            }
        }
    }

    /* for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    } */
    int ans = 0;
    for(int i=1;i<=M;i++)
        ans = max(ans,dp[i][N]);
    cout<<ans;
}