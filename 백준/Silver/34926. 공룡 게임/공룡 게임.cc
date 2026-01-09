#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;

    string str;
    cin>>str;

    vector<bool> dp(N,false);
    dp[0] = true;
    for(int i=0;i<N;i++){
        if(!dp[i]) continue;
        if(i+1<N&&str[i+1]=='_') dp[i+1] = true;
        if(i+K<N&&str[i+K]=='_') dp[i+K] = true;
    }
    cout<<(dp[N-1] ? "YES" : "NO");
}