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

const ll mod = 1e9+7;

ll fpow(ll n, ll p)
{
    if(p==0) return 1LL;
    ll temp = fpow(n,p/2);
    ll ret = temp*temp%mod;
    if(p&1) return ret*n%mod;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,x;
    cin>>N>>x;
    ll sum = 0;
    for(int i=N;i>=0;i--){
        ll a,b;
        cin>>a>>b;
        
        sum += a*fpow(x,b);
        sum%=mod;
    }
    cout<<sum;
}