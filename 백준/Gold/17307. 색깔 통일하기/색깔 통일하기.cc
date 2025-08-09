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
    ll C;
    cin>>N>>C;

    vll v(N);
    for(auto &i : v) cin>>i;

    vll pSum, rpSum;
    pSum.insert(pSum.begin(),0);
    rpSum.insert(rpSum.begin(),0);
    for(int i=0;i<N-1;i++){
        ll temp = v[i+1]-v[i];
        if(temp<0) temp += C;
        pSum.push_back(temp);
    }

    for(int i=0;i<N-1;i++){
        ll temp = v[i]-v[i+1];
        if(temp<0) temp += C;
        rpSum.push_back(temp);
    }

    for(int i=1;i<N;i++){
        pSum[i] += pSum[i-1];
        rpSum[i] += rpSum[i-1];
    }

    ll button, ans = 1e15;

    for(int i=0;i<N;i++){
        ll temp = max(rpSum[i],pSum[N-1]-pSum[i]);
        if(temp<ans){
            button = i+1;
            ans = temp;
        }
    }
    cout<<button<<'\n'<<ans;
}