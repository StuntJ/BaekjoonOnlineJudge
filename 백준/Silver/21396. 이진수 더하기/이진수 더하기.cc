#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while(T--){
        ll N,x;
        cin>>N>>x;

        unordered_map<ll,ll> umap;
        for(int i=0;i<N;i++){
            ll t;
            cin>>t;

            umap[t]++;
        }

        if(x==0){
            ll ans = 0;
            for(auto i : umap){
                ll t = i.second;
                ans += t*(t-1)/2;
            }
            cout<<ans<<'\n';
        }
        else{
            ll ans = 0;
            for(auto i : umap){
                ll val = x^i.first;
                ll num = i.second;
                if(umap.find(val)!=umap.end())
                    ans += num*umap[val];
            }
            cout<<ans/2<<'\n';
        }
    }
}