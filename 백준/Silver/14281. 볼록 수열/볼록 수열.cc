#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> A(N);
	for (auto& i : A) cin >> i;
	ll cnt = 0;
	
	while (true)
	{
		int flag = true;

		for (int i = 1; i <= N - 2; i++)
		{
			int sum = A[i - 1] + A[i + 1];
			if (sum < 2 * A[i])
			{
				cnt += A[i] - sum / 2;
				A[i] = sum / 2;
				flag = false;
			}
		}
		if (flag) break;
	}
	cout << cnt;
}