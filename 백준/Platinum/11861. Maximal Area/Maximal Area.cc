#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> height;

ll maxSquare(int start,int finish)
{
    if(start==finish) return height[start];
    int mid = (start+finish)/2;
    ll ret = max(maxSquare(start,mid),maxSquare(mid+1,finish));

    int lo = mid;
    int hi = mid+1;

    ll minimum = min(height[lo],height[hi]);
    while(lo!=start||hi!=finish)
    {
        ret = max(ret,minimum*(hi-lo+1));
        if(hi+1<=finish&&lo-1>=start)
        {
            if(height[hi+1]>=height[lo-1]) hi++;
            else lo--;
        }
        else if(hi+1<=finish) hi++;
        else if(lo-1>=start) lo--;

        minimum = min(minimum,min(height[lo],height[hi]));
    }
    ret = max(ret,minimum*(hi-lo+1));

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    height.resize(N);
    for(auto &i : height) cin>>i;
    cout<<maxSquare(0,N-1);
}