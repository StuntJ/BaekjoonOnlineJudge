#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<bool> dp(N+1);
    dp[0] = dp[1] = true;
    dp[2] = false;

    for(int i=3;i<=N;i++){
        dp[i] = !(dp[i-1]&&dp[i-3]);
    }
    cout<<(dp[N]? "SK" : "CY");
}