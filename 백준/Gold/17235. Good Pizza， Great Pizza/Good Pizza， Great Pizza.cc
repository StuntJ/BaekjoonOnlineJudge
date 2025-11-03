#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<pair<ll,ll>> v(N);
    for(auto &i : v) cin>>i.first>>i.second;

    sort(v.begin(),v.end(),[&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.first+a.second < b.first+b.second;
    });

    pair<ll,ll> fi = *v.begin();
    pair<ll,ll> se = v.back();

    //cout<<fi.first<<' '<<fi.second<<' '<<se.first<<' '<<se.second<<'\n';

    ll k1 = fi.first+fi.second;
    ll k2 = se.first+se.second;

    ll ans1 = abs(k1-k2);

    sort(v.begin(),v.end(),[&](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.second-a.first<b.second-b.first;
    });

    fi = *v.begin();
    se = v.back();

    //cout<<fi.first<<' '<<fi.second<<' '<<se.first<<' '<<se.second<<'\n';

    k1 = fi.second-fi.first;
    k2 = se.second-se.first;

    ll ans2 = abs(k1-k2);
    //cout<<ans1<<' '<<ans2<<'\n';

    ll ans = max(ans1,ans2);

    auto convert = [&](__int128 t)->string{
        string str;
        if(t==0) str.push_back('0');
        while(t>0){
            str.push_back(t%10+'0');
            t/=10;
        }
        reverse(str.begin(),str.end());
        return str;
    };

    if(ans&1){
        __int128 tot = (__int128)ans*ans/2;
        string str = convert(tot);
        cout<<str<<".5";
    }
    else{
        __int128 tot = (__int128)ans*ans/2;
        string str = convert(tot);
        cout<<str;
    } 

}