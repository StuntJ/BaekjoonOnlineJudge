#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 40;
int dp[MAX_N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = dp[0][1] = 1;
    for(int i=1;i<MAX_N;i++){
        dp[i][0] += dp[i-1][0]+dp[i-1][1];
        dp[i][1] += dp[i-1][0];
    }

    int N,M;
    cin>>N>>M;

    vector<int> v(M);
    for(auto &i : v) cin>>i;

    int vidx = 0;
    int succ = 0;
    int ans = 1;
    for(int i=1;i<=N;i++){
        if(vidx>=M){
            succ++;
        }
        else if(v[vidx]==i){
            if(succ-2>=0) ans *= (dp[succ-2][0] + dp[succ-2][1]);
            //cout<<succ<<' '<<ans<<'\n';
            succ = 0;
            vidx++;
        }
        else{
            succ++;
        }
    }
    if(succ-2>=0)
        ans *= dp[succ-2][0] + dp[succ-2][1];
    cout<<ans;
}