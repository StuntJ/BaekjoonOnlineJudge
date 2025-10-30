#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<ll> A(N);
    for(auto &i : A) cin>>i;

    ll L;
    cin>>L;

    auto chk = [&](ll mid)->bool{
        ll ho = 0;
        for(auto i : A){
            if(i<=mid) ho += mid;
            else ho += 2*(mid-i);
        }
        return ho>=L;
    };

    ll s = 0, e = 1e10;
    ll ans = 1e10;
    while(s<=e){
        ll mid = (s+e)/2;
        if(chk(mid)){
            ans = min(ans,mid);
            e = mid-1;
        }
        else s = mid+1;
    }
    cout<<ans;
}