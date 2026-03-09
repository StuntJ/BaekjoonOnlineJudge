#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<ll> v;

    ll idx = -1;
    ll cnt = 0;
    for(int i=0;i<N;i++){
        ll x;
        cin>>x;
        if(x>0) cnt++;
        else if(x<0) cnt--;

        if(x==0) continue;

        if(idx==-1){
            v.emplace_back(x);
            idx++;
        }
        else{
            if((v[idx]<0 && x>0)||(v[idx]>0 && x<0)){
                if(v[idx]+x>0){
                    cnt++;
                    v[idx]+=x;
                }
                else{
                    v.emplace_back(x);
                    idx++;
                }
            }
            else{
                if(v[idx]<0&&x<0){
                    v[idx] += x;
                    cnt++;
                }
                else{
                    v.emplace_back(x);
                    idx++;
                }
            }
        }
    }

    cout<<(cnt>0 ? "YES" : "NO")<<'\n';     
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin>>t;
    while(t--){
        solve();
    }
}