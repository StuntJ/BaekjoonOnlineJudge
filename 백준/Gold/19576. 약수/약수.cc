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
    cin>>N;
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    sort(v.begin(),v.end());

    vector<int> dp(N,1);
    dp[0] = 1;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(v[i]%v[j]==0){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int sub = *max_element(dp.begin(),dp.end());
    cout<<N-sub;
}