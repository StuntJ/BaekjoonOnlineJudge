#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll n, ll p){
    if(p==0) return 1LL;
    ll temp = fpow(n,p/2);
    ll ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,B;
    cin>>N>>B;

    vector<vector<ll>> dp(N+1,vector<ll>(B+1,1));

    vector<ll> p(N+1),a(N+1),c(N+1);
    
    for(int i=1;i<=N;i++){
        cin>>p[i]>>a[i]>>c[i];
    }

    //dp[0][0] = 1;
    //for(int i=1;i<=N;i++){
        //dp[0][0] *= p[i];
    //}

    for(int i=1;i<=N;i++){
        for(int j=0;j<=B;j++){
            for(int k=0;j-k*c[i]>=0;k++){
                ll mul = p[i]+k*a[i];
                if(mul>=100) mul = 100;
                //if(dp[i-1][j-k*c[i]]==-1) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][j-k*c[i]]*mul);
                if(mul>=100) break;
            }
        }
    }

    
    cout<<dp[N][B]<<'\n';

    int here = N;
    int hereCap = B;

    vector<ll> v;
    while(here!=0){
        for(int k=0;hereCap-k*c[here]>=0;k++){
            ll mul = p[here]+k*a[here];
            if(mul>=100) mul = 100;
            if(dp[here][hereCap]==dp[here-1][hereCap-k*c[here]]*(mul)){
                hereCap-=k*c[here];
                v.push_back(k);
                break;
            }
            if(mul>=100) break;
        }
        here--;
    }
    reverse(v.begin(),v.end());
    for(auto i : v) cout<<i<<' ';
}