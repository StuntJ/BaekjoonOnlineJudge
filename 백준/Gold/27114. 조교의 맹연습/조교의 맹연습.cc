#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B,C,K;
    cin>>A>>B>>C>>K;

    const int INF = 1e9;
    vector<vector<int>> dp(4,vector<int>(K+1,INF));
    dp[0][0] = 0;

    for(int j=1;j<=K;j++){
        for(int n=0;n<4;n++){
            int mn = INF;
            for(int i=0;i<4;i++){
                if(j-A>=0) mn = min(mn,dp[(n-3+4)%4][j-A]);
                if(j-B>=0) mn = min(mn,dp[(n-1+4)%4][j-B]);
                if(j-C>=0) mn = min(mn,dp[(n-2+4)%4][j-C]);
            }
            if(mn!=INF) dp[n][j] = mn+1; 
        }
    }
    cout<<(dp[0][K]==INF ? -1 : dp[0][K])<<'\n';
    /* for(int i=0;i<4;i++){
        for(int j=0;j<=K;j++)
            cout<<(dp[i][j]==INF ? -1 : dp[i][j])<<' ';
        cout<<'\n';
    } */
}