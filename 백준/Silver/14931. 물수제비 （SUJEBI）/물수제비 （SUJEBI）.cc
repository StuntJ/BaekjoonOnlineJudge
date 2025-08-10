#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<ll> v(N);
    for(auto &i : v) cin>>i;
    v.insert(v.begin(),0);

    ll sum = 0;
    ll ans = -1;
    for(int i=1;i<=N;i++){
        ll temp = 0;
        for(int j=i;j<=N;j+=i){
            temp += v[j];
        }
        if(temp>sum){
            sum = temp;
            ans = i;
        }
    }
    if(ans==-1){
        cout<<0<<' '<<0;
        return 0;
    }
    cout<<ans<<' '<<sum;
}