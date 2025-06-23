#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<ll> dpf(N+2),dpg(N+2);
    dpf[1] = 1;
    dpf[2] = 1;
    dpg[1] = 1;
    dpg[2] = 1;
    for(int i=3;i<=N+1;i++){
        dpf[i] = dpf[i-1]+2*dpf[i-2]+3*dpf[i-3];
        dpf[i]%=mod;
        dpg[i] = dpg[i-1]+dpg[i-2]+dpg[i-3];
        dpg[i]%=mod;
    }
    cout<<(dpf[N+1]-dpg[N+1]+mod)%mod;
}