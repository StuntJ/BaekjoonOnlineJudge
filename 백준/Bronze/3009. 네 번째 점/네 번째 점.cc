#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int,int> mp1;
    map<int,int> mp2;

    for(int i=0;i<3;i++)
    {
        int x, y;
        cin>>x>>y;
        mp1[x]++;
        mp2[y]++;
    }
    for(auto i : mp1)
    {
        if(i.second<2) cout<<i.first<<' ';
    }

    for(auto i : mp2)
    {
        if(i.second<2) cout<<i.first<<'\n';
    }
}