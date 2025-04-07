#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true)
    {
        vector<int> v(3);
        for(int i=0;i<3;i++)
            cin>>v[i];
        if(v[0]==0&&v[1]==0&&v[2]==0) return 0;

        sort(v.begin(),v.end());

        if(v[0]+v[1]<=v[2]) cout<<"Invalid\n";
        else if(v[0]==v[1]&&v[1]==v[2]) cout<<"Equilateral\n";
        else if(v[0]==v[1]||v[1]==v[2]||v[0]==v[2]) cout<<"Isosceles\n";
        else cout<<"Scalene\n";
    }
}