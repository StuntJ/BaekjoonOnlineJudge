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

    int N;
    ll K;
    cin>>N>>K;

    vll v(N);
    for(auto &i : v) cin>>i;

    sort(v.begin(),v.end());
    ll ans = numeric_limits<ll>::max();
    for(int i=0;i<N-1;i++){
        ll b1 = v[0]*(i+1);
        ll b2 = v[i+1]*(N-(i+1));
        ll btot = b1+b2;
        ll res = ((K%btot) ? K/btot+1 : K/btot);

        ans = min(ans,res);
    }
    cout<<ans;
}