#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    if(t>645) cout<<45+t-645;
    else if(t>585) cout<<45;
    else if(t>570) cout<<t-540;
    else if(t>390) cout<<30;
    else if(t>360) cout<<t-360;
    else cout<<0;
}