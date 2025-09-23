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

    ll N,M;
    cin>>N>>M;
    
    vll A(N),B(M);
    for(auto &i : A) cin>>i;
    for(auto &j : B) cin>>j;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    ll win = 0, draw = 0, lose = 0;
    for(int i=0;i<N;i++){
        auto it = lower_bound(B.begin(),B.end(),A[i]);
        auto it2 = upper_bound(B.begin(),B.end(),A[i]);
        draw += it2-it;
        win += it-B.begin();
        lose += B.end()-it2;
    }

    cout<<win<<' '<<lose<<' '<<draw;    
}