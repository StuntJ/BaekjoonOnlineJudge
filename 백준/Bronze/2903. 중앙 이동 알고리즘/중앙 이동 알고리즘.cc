#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    typedef long long ll;

    int N;
    cin>>N;

    ll t = 2;   
    for(int i=0;i<N;i++)
    {
        t += t-1;
    }
    cout<<t*t<<'\n';
}