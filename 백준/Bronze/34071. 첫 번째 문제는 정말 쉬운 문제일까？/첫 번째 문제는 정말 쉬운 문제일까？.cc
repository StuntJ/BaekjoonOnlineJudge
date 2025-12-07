#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    int mx = *max_element(v.begin(),v.end());
    int mn = *min_element(v.begin(),v.end());

    if(v[0]==mx) cout<<"hard";
    else if(v[0]==mn) cout<<"ez";
    else cout<<"?";
}