#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve(){
    ll N,H;
    cin>>N>>H;

    vector<array<ll,3>> v(N);
    for(auto &i : v) for(auto &j : i) cin>>j;

    ll totAns = -1;
    for(int i=0;i<(1<<N);i++){
        vector<array<ll,3>> selected;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                selected.push_back(v[j]);
            }
        }

        sort(selected.begin(),selected.end(),[&](array<ll,3> &a, array<ll,3> &b){
            ll t1 = min(a[2],b[2]-a[1]);
            ll t2 = min(b[2],a[2]-b[1]);
            return t1 > t2;
        });

        ll totWeight = 0;
        ll totHeight = 0;
        ll ans = INF;
        for(int j=0;j<selected.size();j++){
            ans = min(ans,selected[j][2]-totWeight);
            totWeight += selected[j][1];
            totHeight += selected[j][0];
        }

        if(totHeight<H) continue;

        if(ans>=0) totAns = max(totAns,ans);

        // for(auto p : selected){
        //     cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<'\n';
        // }
        // cout<<'\n';
    }

    if(totAns==-1) cout<<"Mark is too tall";
    else cout<<totAns;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}