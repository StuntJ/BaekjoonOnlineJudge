#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N,T;
    cin>>N>>T;

    vector<array<ll,3>> v(N);
    for(int i=0;i<N;i++) cin>>v[i][0];
    for(int i=0;i<N;i++) cin>>v[i][1];
    for(int i=0;i<N;i++) cin>>v[i][2];
    
    sort(v.begin(),v.end(),[&](array<ll,3> &a, array<ll,3> &b){
        return a[1]*b[2] > b[1]*a[2];
    });

    vector<ll> dp(T+1);
    for(int i=0;i<N;i++){
        for(int j=T;j>=0;j--){
            if(j+v[i][2]<=T){
                dp[j+v[i][2]] = max(dp[j+v[i][2]],dp[j]+v[i][0]-(j+v[i][2])*v[i][1]);
            }
        }
    }
    
    cout<<*max_element(dp.begin(),dp.end());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }

}