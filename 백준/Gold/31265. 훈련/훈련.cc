#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N,M;
    cin>>N>>M;

    vector<vector<int>> v(N);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v[i].resize(x);
    }

    for(int i=0;i<N;i++) for(auto &j : v[i]) cin>>j;
    
    vector<vector<bool>> dp(N+1,vector<bool>(M+1));
    dp[0][0] = true;

    for(int i=1;i<=N;i++){
        for(int val : v[i-1]){
            for(int j=M;j>=0;j--){
                if(j-val>=0){
                    if(dp[i-1][j-val]||dp[i][j-val]){
                        dp[i][j] = true;
                    }
                }
            }
        }
    }

    for(int j=M;j>=0;j--){
        if(dp[N][j]){
            cout<<j;
            return;
        }
    }
    cout<<-1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}