#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<ll> pSum(N+1,0);
    map<ll,ll> cnt;

    for(int i=1;i<=N;i++)
    {
        ll x;
        cin>>x;
        pSum[i] = pSum[i-1] + x;
        if(cnt.find(pSum[i])==cnt.end()) cnt.insert(make_pair(pSum[i],1));
        else cnt[pSum[i]]++;
    }

    ll ans = 0;

    for(int i=0;i<N;i++)
    {
        ll need = K+pSum[i];
        ans += cnt[need];
        cnt[pSum[i+1]]--;
    }
    cout<<ans;
}
