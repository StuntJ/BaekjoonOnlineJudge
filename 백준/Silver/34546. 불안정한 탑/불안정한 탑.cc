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

    ll m = *min_element(v.begin(),v.end());

    ll ans = 0;
    for(auto i : v) ans += i-m;
    cout<<ans;
}