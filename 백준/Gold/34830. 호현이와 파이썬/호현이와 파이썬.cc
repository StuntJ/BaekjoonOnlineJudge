#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    if(N&1) cout<<N*(N-1)/2<<'\n';
    else cout<<N*(N-1)/2+(N-2)/2;
}