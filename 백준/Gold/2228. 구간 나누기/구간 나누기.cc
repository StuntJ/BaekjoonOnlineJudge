#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    const int INF = 1e9;
    vector<vector<int>> dp(N+1,vector<int>(M+1,-INF));
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);
    dp[1][1] = v[1];
    dp[1][0] = 0;
    for(int i=0;i<=N;i++) dp[i][0] = 0;
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            int mx = -INF;
            for(int k=0;k<=i-2;k++){
                mx = max(mx,dp[k][j-1]);
            }
            if(mx==-INF && dp[i-1][j]==-INF) continue;
            
            dp[i][j] = max(mx,dp[i-1][j])+v[i];
        }
    }
    /* for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    } */
    
    int mx = -INF;
    for(int i=1;i<=N;i++) mx = max(mx,dp[i][M]);
    cout<<mx;
}