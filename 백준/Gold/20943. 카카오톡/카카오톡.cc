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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    map<tuple<bool,ll,ll>,ll> mp;
    for(int i=0;i<N;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        bool sign = false;
        if(a<0){
            sign = !sign;
            a = -a;
        }
        if(b<0){
            sign = !sign;
            b = -b;
        }
        if(a==0||b==0) sign = false;
        ll g = gcd(a,b);
        a/=g; b/=g;
        mp[make_tuple(sign,a,b)]++;
    }

    ll sum = 0;
    ll ans = 0;
    for(auto i : mp){
        ans += sum*i.second;
        sum += i.second;
    }
    cout<<ans;
}