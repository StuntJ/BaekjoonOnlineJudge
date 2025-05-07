#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A;
	cin >> A;
	while (A.size() % 3 != 0)
		A = "0" + A;

	for (int i = 0; i < A.size(); i += 3)
	{
		string p = A.substr(i, 3);
		int k = 0;
		k += (p[0] - '0') * 4;
		k += (p[1] - '0') * 2;
		k += (p[2] - '0') * 1;
		cout << k;
	}
}