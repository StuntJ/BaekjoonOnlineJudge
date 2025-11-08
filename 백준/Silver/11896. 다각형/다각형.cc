#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;

    ll sa = (a-1)/2*((a-1)/2+1);
    ll sb = b/2*(b/2+1);

    if(a-1>=2) sa-=2;
    if(b>=2) sb-=2; 
    cout<<sb-sa;
}