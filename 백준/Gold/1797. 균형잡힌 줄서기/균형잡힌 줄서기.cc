#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<pair<int,int>> vp(N);
    for(int i=0;i<N;i++){
        cin>>vp[i].second>>vp[i].first;
        if(vp[i].second==0) vp[i].second = -1;
    }
    sort(vp.begin(),vp.end());

    map<int,int> mp;
    vector<int> pSum(N);
    for(int i=0;i<N;i++){
        mp[i+1] = vp[i].first;
        pSum[i] = (i>0 ? pSum[i-1] : 0) + vp[i].second;
    }

    pSum.insert(pSum.begin(),0);

    map<int, pair<int,int>> bp;

    for(int i=0;i<=N;i++){
        if(bp.find(pSum[i])==bp.end()) bp[pSum[i]].first = i;
        bp[pSum[i]].second = i;
    }
    int maxi = 0;
    for(auto i : bp){
        if(i.second.second > i.second.first+1)
        maxi = max(mp[i.second.second]-mp[i.second.first+1],maxi);
    }
    cout<<maxi;
}