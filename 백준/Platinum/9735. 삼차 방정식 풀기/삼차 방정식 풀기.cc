#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(4);

	int T;
	cin >> T;
	while (T--)
	{
		ld A, B, C, D;
		cin >> A >> B >> C >> D;

		set<ld> st;

		ld alp;
		for (int i = -1000000; i <= 1000000; i++)
		{
			if (fabs(A * i * i * i + B * i * i + C * i + D) < LDBL_EPSILON)
			{
				alp = i;
				break;
			}
		}
		st.insert(alp);

		B += A * (*st.begin());
		C += B * (*st.begin());

		ld Deter = B * B - 4 * A * C;
		if (Deter >= 0)
		{
			ld fi = (sqrtl(Deter) - B) / (2.0 * A);
			ld se = (-sqrtl(Deter) - B) / (2.0 * A);
			st.insert(fi);
			st.insert(se);
		}
		for (auto i : st) cout << i << ' ';
		cout << '\n';
	}
}