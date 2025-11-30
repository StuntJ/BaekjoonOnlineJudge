#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(5);
    for(auto &i : v) cin>>i;

    sort(v.begin(),v.end());
    int avg = accumulate(v.begin(),v.end(),0)/5;
    cout<<avg<<'\n';
    cout<<v[2]<<'\n';

}