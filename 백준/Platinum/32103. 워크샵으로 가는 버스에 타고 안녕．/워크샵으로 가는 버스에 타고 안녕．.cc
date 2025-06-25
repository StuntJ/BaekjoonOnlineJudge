#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<int> a(N+1,-1),b(N+1,-1);
    for(int i=0;i<M;i++){
        int x,y,t;
        cin>>x>>y>>t;
        if(x==1) a[y] = t;
        else b[y] = t;
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(4,vector<int>(4,INF)));
    for(int i=0;i<4;i++) dp[0][0][i] = 0;

    for(int i=1;i<=N;i++){
        if(a[i]==0&&b[i]==0) continue;
        for(int s=1;s<4;s++){
            if(s==1 && (a[i]==1||b[i]==0)) continue;
            if(s==2 && (a[i]==0||b[i]==1)) continue;
            if(s==3 && (a[i]==0||b[i]==0)) continue;

            for(int t=0;t<4;t++){
                for(int j=0;j<4;j++)
                {
                    if(s!=3 && s==t && (s==j||j==0)) continue;
                    dp[i][s][t] = min(dp[i][s][t],dp[i-1][t][j] + (s==3 ? 2 : 1));
                }
            }
        }
    }


    int ans = INF;
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(i!=3 && (i==j || j==0)) continue;
            ans = min(ans,dp[N][i][j]);
        }
    }
    cout<<(ans==INF ? -1 : ans);
}