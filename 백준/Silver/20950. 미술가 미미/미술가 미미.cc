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

struct rgb{
    int r;
    int g;
    int b;

    int operator - (const rgb &rhs) const{
        return abs(r-rhs.r)+abs(g-rhs.g)+abs(b-rhs.b);
    }
};

rgb mix(vector<rgb> &v){
    int sr = 0, sg = 0, sb = 0;
    int sz = (int)v.size();
    for(auto i : v){
        sr+=i.r;
        sg+=i.g;
        sb+=i.b;
    }
    return {sr/sz,sg/sz,sb/sz};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<rgb> color(N);
    rgb gom;
    for(auto &i : color) cin>>i.r>>i.g>>i.b;
    cin>>gom.r>>gom.g>>gom.b;

    int ans = 1e9;
    vector<rgb> v;

    auto solve = [&](auto &solve, int here, int n)->void{
        if(here==N||n==7){
            if(n>1) ans = min(ans, mix(v)-gom);
            return;
        }
        solve(solve,here+1,n);
        v.emplace_back(color[here]);
        solve(solve,here+1,n+1);
        v.pop_back();
        return;
    };

    solve(solve,0,0);

    cout<<ans;
}