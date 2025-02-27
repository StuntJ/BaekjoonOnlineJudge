#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	if (!N)
	{
		cout << 0;
		return 0;
	}
	bool rev = false;
	if (N < 0) rev = true, N *= -1;

	string S;

	while (N > 0)
	{
		if (N % 3 == 2) S += 'T', N++;
		else S += '0' + N % 3, N -= N % 3;
		N /= 3;
	}
	reverse(S.begin(), S.end());
	if (rev)
	{
		for (auto& ch : S)
		{
			if (ch == 'T') ch = '1';
			else if (ch == '1') ch = 'T';
		}
	}
	cout << S;
}