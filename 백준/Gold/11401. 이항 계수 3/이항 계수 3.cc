#include <bits/stdc++.h>
#define DIV 1000000007
#define MAX_N 4000001

using namespace std;
typedef long long ll;

ll fact[MAX_N];

void initFact()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < MAX_N; i++)
		fact[i] = fact[i - 1] * i % DIV;
}

ll fastPow(ll n, ll p)
{
	if (p == 0) return 1;
	ll temp = fastPow(n, p / 2);
	ll ret = temp * temp % DIV;
	if (p % 2) return ret * n % DIV;
	else return ret;
}

ll bino(ll n, ll r)
{
	ll top = fact[n];
	ll bot = fact[r] * fact[n - r] % DIV;
	bot = fastPow(bot, DIV - 2);
	return top * bot % DIV;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	initFact();
	ll N, r;
	cin >> N >> r;
	cout << bino(N, r);
	/*int N, M;
	cin >> N >> M;

	vector<ll> A(N), B(M);
	for (auto& i : A) cin >> i;
	for (auto& i : B) cin >> i;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	ll maximum = DIV;
	for (int i = 0; i < N; i++)
	{
		if (i < M) maximum = min(maximum, A[i] + B[i]);
		else maximum = min(maximum, A[i]);
	}

	sort(B.begin(), B.end());

	ll ans = 1;
	for (int i = 0; i < N; i++)
	{
		ll need = maximum - A[i];

		ll num = lower_bound(B.begin(), B.end(), maximum - A[i]) - B.begin();
		num = M - num;
		num -= i;
		if (need <= 0) break;
		cout << num << '\n';
		ans *= num;
		ans %= DIV;
	}
	cout << ans;*/
}