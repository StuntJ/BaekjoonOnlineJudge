#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,H;
    cin>>N>>H;

    vector<pair<int,int>> vp;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
    }

    sort(vp.begin(),vp.end());
    vector<ll> len;
    int prev = 0;
    for(int i=0;i<N;i++){
        if(prev+1<vp[i].first){
            len.push_back(vp[i].first-prev-1);
        }
        prev = max(prev,vp[i].second);
    }
    if(prev<H){
        len.push_back(H-prev);
    }
    sort(len.begin(),len.end());
    len.insert(len.begin(),0);
    vector<ll> pSum = len;
    for(int i=1;i<pSum.size();i++){
        pSum[i] += pSum[i-1];
    }
    /* for(auto i : len) cout<<i<<' ';
    cout<<'\n'; */
    int Q;
    cin>>Q;
    int j = pSum.size()-1;
    while(Q--){
        ll Ti;
        cin>>Ti;

        int i = lower_bound(len.begin(),len.end(),Ti)-len.begin();
        if(i>j) cout<<0<<'\n';
        else
            cout<<pSum[j]-pSum[i-1] - (j-i+1)*(Ti-1)<<'\n';
    }

}