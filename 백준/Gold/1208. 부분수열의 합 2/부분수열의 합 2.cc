#include <bits/stdc++.h>
#define MAX_N 41

using namespace std;
typedef long long ll;
ll N,S;
ll arr[MAX_N];
vector<ll> lv,rv;

void MITM(int s, int e, ll sum, vector<ll> &v)
{
    if(s>=e)
    {
        v.push_back(sum);
        return;
    }
    MITM(s+1,e,sum,v);
    MITM(s+1,e,sum+arr[s],v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>arr[i];

    MITM(0,N/2,0,lv);
    MITM(N/2,N,0,rv);

    sort(lv.begin(),lv.end());
    sort(rv.begin(),rv.end());

    ll ans = 0;
    for(ll x: lv) ans += upper_bound(rv.begin(),rv.end(),S-x) - lower_bound(rv.begin(),rv.end(),S-x);
    if(S==0) ans--;
    cout<<ans;
}
