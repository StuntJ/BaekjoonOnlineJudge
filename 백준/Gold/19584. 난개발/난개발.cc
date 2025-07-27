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

    vector<int> seqY(N);
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        seqY[i] = y;
    }

    vector<pair<int,int>> v;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;

        int y1 = seqY[a-1];
        int y2 = seqY[b-1];
        if(y1>y2) swap(y1,y2);
        v.push_back({y1,c});
        v.push_back({y2+1,-c});
    }
    
    sort(v.begin(),v.end());

    ll ans = 0;
    ll cnt = 0;
    for(int i=0;i<v.size()-1;i++){
        cnt += v[i].second;
        ans = max(ans,cnt);
    }
    cout<<ans;
}