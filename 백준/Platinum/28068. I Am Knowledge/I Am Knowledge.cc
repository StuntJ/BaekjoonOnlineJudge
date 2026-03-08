#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<pair<ll,ll>> up, down;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;

        if(a<=b){
            up.push_back({a,b});
        }
        else{
            down.push_back({a,b});
        }
    }

    sort(up.begin(),up.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.first<b.first;
    });

    sort(down.begin(),down.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.second>b.second;
    });

    ll point = 0;
    bool flag = false;
    for(auto p : up){
        point -= p.first;
        if(point<0) flag = true;
        point += p.second;
        if(flag) break;
    }

    for(auto p : down){
        point -= p.first;
        if(point<0) flag = true;
        point += p.second;
        if(flag) break;
    }

    if(flag) cout<<0;
    else cout<<1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1; //cin>>t;
    while(t--){
        solve();
    }
}