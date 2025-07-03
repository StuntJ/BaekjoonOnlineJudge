#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll D;
    cin >> N >> D;

    vector<ll> v(N);
    for (auto &i : v)
        cin >> i;

    ll minE = *min_element(v.begin(), v.end());
    ll maxE = *max_element(v.begin(), v.end());

    if(maxE<=0){
        cout<<D+(-minE)*2;
        return 0;
    }
    else if(minE>=0){
        cout<<D+maxE*2;
        return 0;
    } 

    ll a = -minE;
    ll b = maxE;
    if(a>b) swap(a,b);

    ll ans = 2*(a+b+D);

    ll lD = max(0LL,D-2*(a+b));
    ans = min(ans,4*(a+b)+lD);

    ans = min(ans,4*a+2*b+D);
    cout<<ans;
}