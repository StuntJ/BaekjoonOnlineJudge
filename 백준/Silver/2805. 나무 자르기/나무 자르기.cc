#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    ll H;
    cin>>N>>H;
    vector<ll> v(N);

    for(int i=0;i<N;i++)
        cin>>v[i];

    ll s = 0;
    ll e = 2000000000;
    ll ans;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        ll sum = 0;
        for(auto i:v)
        {
            if(i-mid>0) sum+=i-mid;
        }

        if(sum>=H)
        {
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    cout<<ans;

}
