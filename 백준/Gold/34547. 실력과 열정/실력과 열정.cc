#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int MAX_A = 1001;
    int N;
    cin>>N;

    int A0,B0;
    cin>>A0>>B0;
    int K;
    cin>>K;

    vector<vector<int>> dp(N+1,vector<int>(MAX_A,-1));
    dp[0][A0] = 0;
    for(int i=0;i<N;i++){
        for(int A=0;A<MAX_A;A++){
            if(dp[i][A]==-1) continue;
            int B = A0+B0-A;
            for(int k=K;k<=A;k++) dp[i+1][A-k] = max(dp[i+1][A-k],dp[i][A] + (A-k)*(B+k));
            for(int k=K;k<=B;k++) dp[i+1][A+k] = max(dp[i+1][A+k],dp[i][A] + (A+k)*(B-k));
        }
    }

    int mx = 0;
    for(int i=0;i<MAX_A;i++) mx = max(dp[N][i],mx);
    cout<<mx;
}