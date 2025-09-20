#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    if(N==1){
        cout<<1;
        return 0;
    }
    vector<int> d(N),h(N);
    for(auto &i : d) cin>>i;
    for(auto &i : h) cin>>i;
    list<int> idxList;
    for(int i=0;i<N;i++) idxList.push_back(i);

    ll attack = 0;
    int r = 0;
    vector<bool> chk(N);
    vector<ll> sta(N);
    int pp = 0;

    auto it = idxList.begin();
    while(true){
        int idx = *it;
        ll here = h[idx]-attack + sta[idx];
        bool flag = false;
        if(here<=0){
            if(!chk[idx]){
                pp++;
                chk[idx] = true;
                flag = true;
                it = idxList.erase(it);
            }
            if(pp==N-1) break;
        }
        else{
            attack += d[idx];
            sta[idx] += d[idx];
        }
        if(!flag)
            it = next(it);
        if(it==idxList.end()) it = idxList.begin();
    }
    for(int i=0;i<N;i++) if(!chk[i]) cout<<i+1;
}