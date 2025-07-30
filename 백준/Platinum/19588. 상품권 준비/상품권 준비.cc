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

    vpi v(N+1);
    vll xorSum(N+1),pSum(N+1);
    for(int i=1;i<=N;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin()+1,v.end(),greater<pi>());
    for(int i=1;i<=N;i++) xorSum[i] = (xorSum[i-1]^v[i].second);
    for(int i=1;i<=N;i++) if(i>=M) pSum[i] = pSum[i-M] + (xorSum[i]^xorSum[i-M]);
    int Q;
    cin>>Q;
    while (Q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<pSum[b+a*M]-pSum[b]<<'\n';
    }
    
}