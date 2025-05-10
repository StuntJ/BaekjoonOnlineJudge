#include <bits/stdc++.h>

using namespace std;

const int LIM = 201;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> fac(LIM,vector<int>(LIM,0));

	for (int i = 1; i < LIM; i++)
	{
		int n = i;
		for (int j = 2; j * j <= n; j++)
		{
			while (n % j == 0)
			{
				fac[i][j]++;
				n /= j;
			}
		}

		if (n > 1)
			fac[i][n]++;
		for (int j = 1; j < LIM; j++)
			fac[i][j] += fac[i - 1][j];
	}

	string str;
	typedef long long ll;
	auto fpow = [&](auto& fpow, ll n, ll p)->ll
	{
		if (p == 0) return 1;
		ll temp = fpow(fpow, n, p / 2);
		ll ret = temp * temp;
		if (p & 1) return ret * n;
		return ret;
	};

	while (N != 0 && M != 0)
	{
		vector<int> f(LIM);
		for (int i = 1; i < LIM; i++) f[i] = fac[N-1 + M][i] - fac[N-1][i] - fac[M][i];
		

		ll mul = 1;

		for (ll i = 1; i < LIM; i++)
		{
			mul*= fpow(fpow,i, (ll)f[i]);
			if (mul >= K) break;
		}
		if (mul >= K) 
		{
			str.push_back('a');
			N--;
		}
		else
		{
			str.push_back('z');
			M--;
			K -= mul;
		}
	}

	while (N)
	{
		str.push_back('a');
		N--;
	}
	while (M)
	{
		str.push_back('z');
		M--;
	}
	if (K > 1) cout << -1;
	else cout << str;
}