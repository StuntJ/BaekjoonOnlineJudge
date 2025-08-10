#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,t;
    cin>>N>>t;

    vector<pair<ll,ll>> v(N);
    for(auto &i : v) cin>>i.first>>i.second;

    sort(v.begin(),v.end());

    ll ans = 0;
    int prev = 0;
    for(int i=1;i<N;i++){
        ll temp = t*v[prev].first+v[prev].second- t*v[i].first;
        if(temp>0){
            ans += min(temp,v[i].second);
            if(temp<=v[i].second) prev = i;
        }
        else prev = i; 
    }
    cout<<ans;
}