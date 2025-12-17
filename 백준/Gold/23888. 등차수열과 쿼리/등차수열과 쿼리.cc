#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll &a, ll &b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,d;
    ll q;
    cin>>a>>d>>q;
    while(q--){
        ll t;
        ll l,r;
        cin>>t>>l>>r;

        ll al = a+(l-1)*d;
        ll ar = a+(r-1)*d;

        if(t==1){
            cout<<(r-l+1)*(al+ar)/2<<'\n';
        }
        else if(t==2){
            if(l==r) cout<<al<<'\n';
            else cout<<gcd(al,d)<<'\n';
        }
    }
}