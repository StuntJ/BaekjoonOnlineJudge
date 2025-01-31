#include <bits/stdc++.h>

using namespace std;

double cal(double prev, double next, int sign)
{
	if (sign == 0) return prev + next;
	else if (sign == 1) return prev - next;
	else if (sign == 2) return prev * next;
	else
	{
		/*if (next == 0.0) return -9.13214124;*/
		return prev / next;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		vector<double> v(4);
		for (auto& a : v) cin >> a;
		sort(v.begin(), v.end());

		bool flag = false;

		do
		{
			/*for (auto i : v) cout << i << ' ';
			cout << '\n';*/
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						vector<double> res;
						res.push_back(cal(cal(v[0], v[1], i), cal(v[2], v[3], k), j));
						res.push_back(cal(cal(cal(v[0], v[1], i), v[2], j), v[3], k));
						res.push_back(cal(cal(v[0], cal(v[1], v[2], j), i), v[3], k));
						res.push_back(cal(v[0], cal(cal(v[1], v[2], j), v[3], k), i));
						res.push_back(cal(v[0], cal(v[1], cal(v[2], v[3], k), j), i));
						for (auto t : res)
						{
							if (fabs(t - 24.0) <= 1e-9) flag = true;
						}
					}
				}
			}
			if (flag) break;
		} while (next_permutation(v.begin(), v.end()));
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}