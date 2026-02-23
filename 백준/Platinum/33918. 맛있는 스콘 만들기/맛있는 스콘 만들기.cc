#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N,M,C,D;
    cin>>N>>M>>C>>D;

    vector<int> B(N);
    for(auto &i : B) cin>>i;

    vector<deque<int>> dq(C);
    vector<int> dqIdx(C);
    vector<vector<int>> dp(N,vector<int>(M+1));
    for(int i=1;i<=M;i++){
        dp[0][i] = M-abs(B[0]-i);
    }

    for(int i=1;i<N;i++){

        for(int j=1;j<=C;j++){
            dqIdx[j%C] = j;
            dq[j%C].clear();
            dq[j%C].push_back(j);
        }

        for(int j=1;j<=M;j++){

            while(dqIdx[j%C]<j+D){
                int idx = dqIdx[j%C]+C;
                if(idx>M) break;
                dqIdx[j%C] = idx;
                while(!dq[j%C].empty()&&dp[i-1][dq[j%C].back()]<dp[i-1][idx]){
                    dq[j%C].pop_back();
                }
                dq[j%C].push_back(idx);
            }

            while(!dq[j%C].empty() && dq[j%C].front()<j-D){
                dq[j%C].pop_front();
            }

            int k = dq[j%C].front();
            dp[i][j] = dp[i-1][k] + M - abs(B[i]-j);
        }
    }

    int mx = 0;
    for(int i=1;i<=M;i++) mx = max(mx,dp[N-1][i]);
    cout<<mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}