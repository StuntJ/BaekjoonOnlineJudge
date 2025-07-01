#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll L;
    cin>>L;
    ll ML,MK;
    cin>>ML>>MK;
    ll cammo;
    cin>>cammo;
    vector<ll> pSum(1,0);
    vector<ll> v(L+1);
    for(int i=1;i<=L;i++) cin>>v[i];
    bool flag = true;
    for(int i=1;i<=L;i++){
        ll minus = pSum[i-1]-pSum[max(0LL,i-ML)];
        //cout<<"minus : "<<minus<<'\n';
        ll x = v[i];
        x-=minus;
        if(x>MK){
            if(cammo) cammo--;
            else{
                flag = false;
                break;
            }
            ll pl = pSum.back();
            pSum.push_back(pl);
        }
        else{
            ll pl = pSum.back()+MK;
            pSum.push_back(pl);
        }
    }
    cout<<(flag ? "YES" : "NO");
}