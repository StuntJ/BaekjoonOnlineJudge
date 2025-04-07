#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> mp;
    int M = 0;
    int sum =0;
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        M = max(M,++mp[x]);
    }
    if(sum!=180) cout<<"Error";
    else if(M==3) cout<<"Equilateral";
    else if(M==2) cout<<"Isosceles";
    else cout<<"Scalene";
}