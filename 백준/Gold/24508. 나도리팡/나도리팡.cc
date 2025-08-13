#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K,T;
    cin>>N>>K>>T;
        
    typedef long long ll;
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    if(sum%K!=0)
    {
        cout<<"NO";
        return 0;
    }
    sort(v.begin(),v.end());
    ll idx = sum/K;
    ll times = accumulate(v.begin(), v.end()-idx, 0LL);
    cout<<(times>T ? "NO" : "YES");
}
