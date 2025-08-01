#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//밀러 라빈 테스트
//소수인 a, N에 대해 a^(N-1) ≡ 1(modN) 이 성립한다. 그리고 N이 밑 a 유사소수여도 성립한다. 단 N이 a을 나누면 성립하지 않는다.
//N이 a를 나누면 N==1 || N==a 이나 N은 소수이므로 N==a 이고 N은 소수이다.
// 다음은 N이 a를 나누지 않아 식이 성립할 때의 상황이다.
//N은 2이상일때 짝수이며 N-1 = 2^r * d 로 표현 가능하다.
//r>0 이면 N-1 = (2^(r-1)*d)^2 ≡ 1(modN) 그러므로 2^(r-1)*d ≡ 1(modN) or 2^(r-1)*d≡-1≡N-1(modN) 이다.
//후자의 경우 더 이상 판별할 수 없으므로 N은 소수라고 판별한다. (이래서 확률적으로 소수를 판단한다는 것이다.)
//전자의 경우 r-1>0이라면 한번 더 제곱꼴로 고쳐서 뜯어낸 후 판별을 진행한다. (계속 N-1에 2의 인수가 남아있다면 없을 때까지 나눈다.)
//만약 modN의 값이 -1 ≡ N-1(modN) 이나 1이 아니면 N은 소수가 될 수 없으므로 합성수로 판별한다.
// 밑 a가 {2,7,61}인 경우 int32까지, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}인 경우 unsigned int64 까지 충분히 판별해낼 수 있다. (단, 오버플로우를 방지해야한다.)
// 다음 코드는 int32까지 판별할 수 있는 코드이다.

typedef unsigned long long ull;

ll mul(ll x, ll y, ll mod) { return (__int128)x*y%mod; }

ll fastPow(ll n, ll p, ll mod) //빠른 곱셈 알고리즘
{
    if (p == 0LL) return 1;
    ll temp = fastPow(n, p / 2, mod);
    ll ret = mul(temp,temp,mod);//int64까지 적용시 오버플로우를 방지하는 함수를 써야 한다. (addmod, mulmod)
    if (p % 2) return mul(ret,n,mod);
    return ret%mod;
}

bool miller_rabin(ll x, ll a)
{
        if (x % a == 0) return 0;
        ll d = x - 1;
        while (1)
        {
            ll tmp = fastPow(a, d, x);
            if (d & 1) return (tmp != 1 && tmp != x - 1);
            else if (tmp == x - 1) return 0;
            d >>= 1;
        }
    }
bool isPrime(ll x)
{
    for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 })
    {
        if (x == i) return 1;
        if (x > 40 && miller_rabin(x, i)) return 0;
    }
    if (x <= 40) return 0;
    return 1;
}

void solve(ll n,vector<ll> &v)
{
    //cout<<1<<'\n';
    if(n==1) return;
    if(n%2==0)
    {
        v.emplace_back(2);
        solve(n/2,v);
        return;
    }
    if(isPrime(n))
    {
        v.emplace_back(n);
        return;
    }
    
    ll a,b,c,g = n;
    auto f = [&](ll x)
    {
        return (c+mul(x, x, n))%n;
    };
    
    do {
        if(g==n)
        {
            a = b = rand()%(n-2)+2;
            c = rand()%20+1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs(a-b),n);
    } while (g==1);
    solve(g,v);
    solve(n/g,v);
}

vector<ll> factorize(ll n)
{
    vector<ll> ret;
    solve(n,ret);
    sort(ret.begin(),ret.end());
    return ret;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin>>N;

    vector<ll> ans = factorize(N);
    if(ans.size()==1){
        cout<<-1<<'\n';
        return 0;
    }

    vector<ll> res;
    for(int i=1;i<ans.size();i+=2){
        res.push_back(ans[i]*ans[i-1]);
    }
    if(ans.size()&1)
        res[res.size()-1]*=ans.back();
    
    for(auto &i : res) cout<<i<<' ';
}   