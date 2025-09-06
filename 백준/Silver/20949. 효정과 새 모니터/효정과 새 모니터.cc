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

const double D = 77.0;

struct mon{
    int x;
    int y;
    int idx;

    bool operator < (const mon &rhs) const{
        if(x*x+y*y==rhs.x*rhs.x+rhs.y*rhs.y) return idx<rhs.idx;
        return x*x+y*y>rhs.x*rhs.x+rhs.y*rhs.y;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<mon> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i].x>>v[i].y;
        v[i].idx = i+1;
    }
    sort(v.begin(),v.end());

    for(auto &i : v) cout<<i.idx<<'\n';
}