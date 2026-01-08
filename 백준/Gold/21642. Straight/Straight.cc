#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n,m,s;
    cin>>n>>m>>s;

    vector<ll> com(m);
    for(auto &i : com) cin>>i;
    sort(com.begin(),com.end());

    com.erase(unique(com.begin(),com.end()),com.end());

    ll minNum = m-s;

    if(com.size()<minNum){
        cout<<0<<'\n';
        return;
    }

    ll a = 1;
    ll b = 1;
    ll ans = 0;
    com.insert(com.begin(),0);

    while(b<com.size()){
        while(b-a+1>minNum || com[b]-com[a]+1>m){
            a++;
        }

        if(b-a+1==minNum){
            int lb = min(n-m+2,max(com[a-1]+1,com[b]-m+1));
            int rb = min(n-m+1,com[a]);
            ans += rb-lb+1;
        }
        b++;
    }
    
    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}