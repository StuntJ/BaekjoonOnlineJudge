#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> v(21);
    v[0] = 1;
    for(int i=2;i<21;i++) v[i] = (i-1)*(v[i-1]+v[i-2]);

    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N;
        cout<<v[N]<<'\n';
    }
}