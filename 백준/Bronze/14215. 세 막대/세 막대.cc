#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v(3);
    for(auto &i : v) cin>>i;

    sort(v.begin(),v.end());
    while(v[0]+v[1]<=v[2])
        v[2]--;
    
    cout<<accumulate(v.begin(),v.end(),0);
}