#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;

		unordered_set<int> st;
		while (A > 0)
		{
			st.insert(A);
			A >>= 1;
		}

		int ans = 0;
		while (B > 0)
		{
			if (st.find(B) != st.end())
			{
				ans = B;
				break;
			}
			B >>= 1;
		}
		cout << ans*10 << '\n';
	}
}