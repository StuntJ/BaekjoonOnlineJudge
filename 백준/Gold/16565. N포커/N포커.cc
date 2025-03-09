#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
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
const ll DIV = 10007;
ll fact[FACTLIM];

void initFact(ll mod = DIV) //FACTLIM을 설정 후에 사용
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < FACTLIM; i++)
		fact[i] = fact[i - 1] * i % mod;
}

ll fastPow(ll n, ll p, ll mod = DIV)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2, mod);
	ll ret = temp * temp % mod;
	if (p & 1) return ret * n % mod;
	return ret;
}

ll bino(ll n, ll r, ll mod = DIV) //initFact를 실행한 다음 사용
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

	initFact();

	int N;
	cin >> N;

	ll ans = 0;
	for (int i = 4; i <= N; i+=4)
	{
		if ((i / 4) & 1)
		{
			ans += bino(13, i / 4) * bino(52 - i, N - i);
			ans %= DIV;
		}
		else
		{
			ans -= bino(13, i / 4) * bino(52 - i, N - i) % DIV;
			ans = (ans + DIV) % DIV;
		}
	}
	cout << ans;
}