#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<ll,ll>> paint(N+1);

    for(int i=1;i<=N;i++)
    {
        cin>>paint[i].first>>paint[i].second;
    }

    paint[0] = make_pair(0,0);
    sort(paint.begin()+1,paint.end());

    vector<ll> val(N+1,0);

    for(int i=1;i<=N;i++)
        paint[i].second += paint[i-1].second;

    ll ans = 0;
    ll M, m = paint[1].first;
    for(int i=1;i<=N;i++)
    {
        M = paint[i].first;
        ll now = paint[i].second-M+m;
        ans = max(ans,now);
        if(i==N) break;
        m = max(m,paint[i+1].first-paint[i].second);
    }

    cout<<ans;
}
