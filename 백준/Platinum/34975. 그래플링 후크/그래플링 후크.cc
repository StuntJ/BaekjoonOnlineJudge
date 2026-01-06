#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    map<int,int> mp;

    int N;
    cin>>N;

    vector<pair<int,pair<int,int>>> v(N);
    for(int i=0;i<N;i++){
        v[i].first = i;
        cin >> v[i].second.first >> v[i].second.second;
        int dist = abs(v[i].second.first) + abs(v[i].second.second);
        mp[dist]++;
    }
    sort(v.begin(),v.end(),[&](pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
        return abs(a.second.first)+abs(a.second.second) < abs(b.second.first)+abs(b.second.second);
    });

    vector<pair<int,int>> ans(N);
    
    int M;
    cin>>M;

    while(M--){
        int l;
        cin>>l;
        
        auto p = mp.upper_bound(l);
        if(p==mp.begin()) continue;
        p = prev(p);
        int dist = p->first; 
        if(p!=mp.begin() && prev(p)->first==dist-1){
            mp[prev(p)->first] += p->second;
        }
        else{
            mp[(p->first)-1] = p->second;
        }
        mp.erase(p);
    }

    int idx = 0;
    for(auto i : mp){
        int dist = i.first;
        int it = i.second;
        if(dist<0) dist = 0;
        while(it--){
            int absx = abs(v[idx].second.first);
            int absy = abs(v[idx].second.second);
            bool signx = (v[idx].second.first >= 0) ? false : true;
            bool signy = (v[idx].second.second >= 0) ? false : true; 
            int minus = absx + absy - dist;
            if(minus>absx){
                minus-=absx;
                absx = 0;
                absy -= minus;
            } 
            else{
                absx -= minus;
            }

            int x = absx * (signx ? -1 : 1);
            int y = absy * (signy ? -1 : 1);
            ans[v[idx].first] = {x,y};
            idx++;
        }
    }

    for(auto &i : ans) cout<<i.first<<' '<<i.second<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}