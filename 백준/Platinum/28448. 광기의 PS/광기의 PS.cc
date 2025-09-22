#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll L;
    cin>>N>>L;

    struct v_data{
        ll K;
        ll T;

        bool operator < (const v_data &rhs) const{
            //return K*(T-5) < rhs.K*(rhs.T-5);
            return K>rhs.K;
        }
    };

    vector<v_data> v(N);
    vector<ll> alpha(N);
    for(auto &i : v) cin>>i.K>>i.T;

    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        alpha[i] = max(0LL,v[i].K*(v[i].T-5));
    }

    ll delay = 0;
    ll ans = 0;
    for(int i=0;i<N;i++){
        ll plus = max(0LL,delay + v[i].K*v[i].T-L);
        //cout<<plus<<' '<<delay<<'\n';
        ans += plus;
        delay = delay + max(0LL,alpha[i] - plus);
    }
    for(int i=0;i<N;i++) ans += v[i].T;
    cout<<ans;
}