#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<pair<ll,ll>> up,down;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;

        if(a<=b) up.push_back({a,b});
        else down.push_back({a,b});
    }

    sort(up.begin(),up.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.first<b.first;
    });

    sort(down.begin(),down.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.second>b.second;
    });

    ll ans = 0;
    ll point = 0;
    for(auto p : up){
        point -= p.first;
        ans = min(ans,point);
        point += p.second;
    }

    for(auto p : down){
        point -= p.first;
        ans = min(ans,point);
        point += p.second;
    }

    cout<<-ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}