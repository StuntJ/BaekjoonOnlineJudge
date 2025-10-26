#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> Lc(N),Rc(N);
    for(auto &i : Lc) cin>>i;
    for(auto &i : Rc) cin>>i;

    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    dp[0][0] = 0;

    for(int L=0;L<=N;L++){
        for(int R=0; R<=N; R++){
            if(L>=1&&R!=N&&dp[L-1][R]!=-1)  dp[L][R] = dp[L-1][R];
            if(L>=1&&R>=1&&dp[L-1][R-1]!=-1) dp[L][R] = max(dp[L][R],dp[L-1][R-1]);
            if(L!=N && R>=1 && Lc[L]>Rc[R-1]&&dp[L][R-1]!=-1) dp[L][R] = max(dp[L][R],dp[L][R-1]+Rc[R-1]); 
        }
    }

    /* for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++) cout<<dp[i][j]<<' ';
        cout<<'\n';
    } */

    int ans = 0;
    for(int i=0;i<=N;i++) if(dp[i][N]!=-1) ans = max(ans,dp[i][N]);
    for(int i=0;i<=N;i++) if(dp[N][i]!=-1) ans = max(ans,dp[N][i]);
    cout<<ans;
}