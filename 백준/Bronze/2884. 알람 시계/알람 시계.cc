#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, M;
	cin >> H >> M;

	if (M >= 45) cout << H << ' ' << M-45;
	else
	{
		H = (H - 1 + 24) % 24;
		M = (M - 45 + 60) % 60;
		cout << H << ' ' << M;
	}
}