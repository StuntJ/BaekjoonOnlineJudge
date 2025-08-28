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

    vector<int> prime;
    auto getPrime = [&](int n)->void{
        vector<int> isPrime(n+1,true);
        isPrime[1] = false;
        isPrime[0] = false;

        for(int i=2;i*i<=n;i++)
            for(int j=i*i;j<=n;j+=i)
                isPrime[j] = false;
        
        for(int i=2;i<=n;i++) if(isPrime[i]) prime.push_back(i);
    };

    getPrime(N);
    //for(int i=0;i<prime.size();i++) cout<<prime[i]<<'\n';

    const ll mod = 123456789;
    vector<ll> dp(N+1);
    dp[0] = 1;
    for(int i=0;i<prime.size();i++){
        for(int j=0;j+prime[i]<=N;j++){
            dp[j+prime[i]] += dp[j];
            dp[j+prime[i]] %= mod;
        }
    }
    cout<<dp[N];
}