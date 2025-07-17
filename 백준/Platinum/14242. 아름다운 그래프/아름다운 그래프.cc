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

const int FACTLIM = 100001; //팩토리얼 제한 
const ll mod = 1e9+7;
ll fact[FACTLIM];

void initFact(ll mod) //FACTLIM을 설정 후에 사용
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < FACTLIM; i++)
        fact[i] = fact[i - 1] * i % mod;
}

ll fastPow(ll n, ll p, ll mod)
{
    if (p == 0) return 1;
    ll temp = fastPow(n, p / 2, mod);
    ll ret = temp * temp % mod;
    if (p & 1) return ret * n % mod;
    return ret;
}

ll bino(ll n, ll r, ll mod) //initFact를 실행한 다음 사용
{
    ll top = fact[n];
    ll bot = fact[r] * fact[n - r] % mod;
    bot = fastPow(bot, mod - 2, mod);
    return top * bot % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    initFact(mod);
    ll lastmul = fact[N] * fastPow(2,mod-2,mod) % mod;
    ll sum = 0;
    for(int x=0;x<(1<<(N-1));x++){
        int idx = 0;
        ll temp = 0;
        for(int i=0;i<(N-1);i++){
            int var = (1<<i);
            if(!(var&x)) idx++;
            else{
                if(idx>=2){
                    temp+=bino(idx,2,mod);
                    temp%=mod;
                }
                idx = 0;
            }
        }
        if(idx>=2){
            temp+=bino(idx,2,mod);
            temp%=mod;
        }
        sum += fastPow(2,temp,mod);
        sum%=mod;
    }


    sum = sum*lastmul%mod;
    cout<<sum;

}