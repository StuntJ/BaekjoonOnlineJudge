#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int X, Y, Z;
	cin >> X >> Y >> Z;

	if (X - 2 <= 0 || Y - 2 <= 0 || Z - 2 <= 0)
	{
		cout << 0;
		return 0;
	}
	if (X == 3 && Y == 3 && Z == 3)
	{
		cout << 0;
		return 0;
	}

	cout << (min(X, min(Y, Z)) - 1) / 2;
}