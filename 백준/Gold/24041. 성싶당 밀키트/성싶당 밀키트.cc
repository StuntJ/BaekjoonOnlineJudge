#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,G,K;
    cin>>N>>G>>K;

    vector<array<ll,3>> v(N);
    for(int i=0;i<N;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];

    ll s = 0, e = 1e10;
    ll ans = 0;
    priority_queue<ll> pq;
    while(s<=e){
        ll mid = (s+e)/2;
        ll sum = 0;
        for(int i=0;i<N;i++){
            ll temp = v[i][0] * max(1LL,mid-v[i][1]);
            if(!v[i][2]) sum+=temp;
            else{
                pq.push(temp);
            }
        }
        ll t = K;
        while(!pq.empty() && t--){
            pq.pop();
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        if(G>=sum){
            s = mid+1;
            ans = max(ans,mid);
        }
        else e = mid-1;
    }
    cout<<ans;
}