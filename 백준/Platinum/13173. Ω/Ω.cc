#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll fpow(ll n, ll p){
    if(p==0) return 1;
    ll temp = fpow(n,p/2);
    ll ret = temp*temp%mod;
    if(p&1) return ret*n%mod;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll P,Q,N,K;
    cin>>P>>Q>>N>>K;

    if(K==0){
        cout<<0;
        return 0;
    }
    else if(K==N){
        cout<<1;
        return 0;
    }
    else if(Q==0){
        cout<<1;
        return 0;
    }
    else if(Q==P){
        cout<<0;
        return 0;
    }
    
    if(Q*2==P){
        cout<<K*fpow(N,mod-2)%mod;
        return 0;
    }

    ll u = Q*fpow(P,mod-2)%mod;
    ll t = u*fpow(1-u+mod,mod-2)%mod;

    ll top = (1-fpow(t,K)+mod)%mod;
    ll bot = (1-fpow(t,N)+mod)%mod;

    ll ret = top*fpow(bot,mod-2)%mod;
    cout<<ret;
}