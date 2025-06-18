#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int calAns(int length,vector<ll> lanlength)
{
    int ans = 0;
    for(auto i : lanlength)
    {
        ans+=i/length;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K,N;
    cin>>K>>N;

    ll Max = 0;
    vector<ll> lanlength(K);

    for(int i=0;i<K;i++)
    {
        cin>>lanlength[i];
        Max = max(Max,lanlength[i]);
    }

    sort(lanlength.begin(),lanlength.end());
    ll low= 1;
    ll high = Max;
    ll mid;
    while(high-low>=0)
    {
        mid = (high+low)/2;
        if(calAns(mid,lanlength)>=N) low = mid+1;
        else high = mid-1;
    }
    cout<<high;
}
