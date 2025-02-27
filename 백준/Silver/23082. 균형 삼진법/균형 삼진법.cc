#include <bits/stdc++.h>

using namespace std;

int fastPow(int n, int p)
{
	if (p == 0) return 1;
	int temp = fastPow(n, p / 2);
	int ret = temp * temp;
	if (p & 1) return ret * n;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	bool rev = false;
	if (N < 0) rev = true, N *= -1;
	int lim = (int)floor(log10(N) / log10(3));
	vector<int> ans;

	for (int i = lim; i >= 0; i--)
	{
		int bit = fastPow(3, i);
		ans.push_back(N / bit);
		N %= bit;
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] >= 2) 
		{
			ans[i] -= 3;
			if (i + 1 < ans.size()) ans[i + 1]++;
			else ans.push_back(1);
		}
	}
	reverse(ans.begin(), ans.end());
	if (rev) for (auto& i : ans) i *= -1;

	for (auto i : ans)
	{
		if (i == -1) cout << 'T';
		else cout << i;
	}
}