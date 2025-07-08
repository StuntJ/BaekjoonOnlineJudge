#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    int sum = 0;
    while(x!=-1){
        cin>>x;
        if(x!=-1)
            sum+=x;
    }
    cout<<sum;
}