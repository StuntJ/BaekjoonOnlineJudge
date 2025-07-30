#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<array<ll,3>> v;
    vector<pair<ll,ll>> shop(M);

    for(int i=0;i<N;i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y+1,1});
        v.push_back({y+1,-1,-1});
    }
    sort(v.begin(),v.end());

    for(int i=0;i<M;i++){
        cin>>shop[i].first>>shop[i].second;
    }
    sort(shop.begin(),shop.end());

    int idx = 0;
    ll cnt = 0;
    multiset<ll> mset;
    for(int i=0;i<v.size();i++){
        while(idx<M && shop[idx].first<v[i][0]){
            ll lim = shop[idx].second;
            while(!mset.empty()&&lim){
                if(*mset.begin()>=shop[idx].first) cnt++;
                mset.erase(mset.begin());
                lim--;
            }
            idx++;
        }
        if(v[i][1]==-1){
            auto it = mset.find(v[i][0]);
            if(it!=mset.end()) mset.erase(it);
        } 
        else{
            mset.insert(v[i][1]);
        }
    }
    cout<<cnt;
}