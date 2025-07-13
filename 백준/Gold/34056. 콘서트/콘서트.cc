#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<ll> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    int Q;
    cin>>Q;
    while(Q--){
        int q;
        cin>>q;
        if(q==1){
            ll c,x;
            cin>>c>>x;
            ll lc = x, rc = x;
            ll l = c, r = c+1;
            while(lc>0 && l>0){
                ll val = min(v[l],lc);
                lc -= val;
                v[l]+=val;
                l--;
            }
            while(rc>0&&r<=N){
                ll val = min(v[r],rc);
                rc -=val;
                v[r]+=val;
                r++;
            }
        }
        else{
            int c;
            cin>>c;
            cout<<v[c]<<'\n';
        }
    }
}