#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int A,B;
    cin>>N;
    cin>>A>>B;

    vector<ll> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);
    sort(v.begin(),v.end());
    vector<ll> pSum(N+1);
    for(int i=1;i<=N;i++) pSum[i] = pSum[i-1]+v[i];
    const int INF = 1e9;
    vector<ll> dp(N+1,INF);
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        dp[i] = min(dp[i],dp[i-1]+A*v[i]);
        for(int j=i;j<=min(N,(i+39));j++){
            int mid = (i+j)/2;
            ll res = 0;
            if((j-i+1)&1) res+=v[mid];
            res += -(pSum[mid]-pSum[i-1]) + (pSum[j]-pSum[mid]);
            dp[j] = min(dp[j],dp[i-1]+res*A+B); 
        }
    }
    cout<<dp[N];
}