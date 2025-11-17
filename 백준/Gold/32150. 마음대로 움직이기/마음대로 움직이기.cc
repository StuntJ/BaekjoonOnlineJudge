#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e11;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll K;
    cin>>K;

    vector<pair<ll,ll>> vp;
    ll prev = -INF;
    for(int i=0;i<K;i++){
        ll x;
        cin>>x;
        vp.push_back({prev,x});
        prev = x;
    }
    vp.push_back({prev,INF});

    ll sz = vp.size();

    int Q;
    cin>>Q;
    while(Q--){
        ll T,P;
        cin>>T>>P;

        ll s = 0, e = sz;
        ll idx = 0;
        while(s<=e){
            ll mid = (s+e)/2;
            if(P<=vp[mid].first){
                e = mid-1;
            }
            else if(P>=vp[mid].second){
                s = mid+1;
            }
            else{
                idx = mid;
                break;
            }
        }

        ll rangeMin = max(P-T-1,vp[idx].first);
        ll rangeMax = min(P+T+1,vp[idx].second);

        //cout<<vp[idx].first<<' '<<vp[idx].second<<'\n';
        //cout<<rangeMin<<' '<<rangeMax<<'\n';
        ll tot = rangeMax-rangeMin-1;
        ll evenRangeMin = (rangeMin+INF)/2;
        ll evenRangeMax = (rangeMax-1+INF)/2;
        ll totEven = evenRangeMax-evenRangeMin;
        ll totOdd = tot-totEven;
        //cout<<evenRangeMin<<' '<<evenRangeMax<<'\n';
        //cout<<totEven<<'\n';
        //cout<<P<<'\n';

        if((T+P)&1){  // p is odd
            cout<<totOdd<<'\n';
        }
        else{
            cout<<totEven<<'\n';
        }
    }
}