#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    ll L;
    cin>>L;

    vector<pair<ll,ll>> vp(N);

    for(int i=0;i<N;i++){
        ll x;
        cin>>x;
        vp[i].first = x-L;
        vp[i].second = x+L;
    }

    sort(vp.begin(),vp.end());

    const ll INF = 1e9*2;
    ll here = -INF;
    ll ans = 0;
    for(int i=1;i<N;i+=2){
        ll back = max(0LL,vp[i-1].second-vp[i].first);
        ll front = 0;
        ll tot = 0;
        ll coid = 0;
        if(i!=N-1){
            front = max(0LL,vp[i].second-vp[i+1].first);
            coid = max(0LL,vp[i-1].second-vp[i+1].first);
        }

        ll minus = max(0LL,here-vp[i].first);
        //cout<<back<<' '<<front<<' '<<tot<<' '<<coid<<'\n';
        tot = front+back-coid-minus;
        ans += tot;
        here = vp[i].second;
    }
    cout<<ans;
}