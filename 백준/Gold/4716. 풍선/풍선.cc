#include <bits/stdc++.h>

using namespace std;
struct v_data
{
	int K;
	int Da;
	int Db;

	bool operator < (const v_data& rhs) const
	{
		return abs(Da - Db) > abs(rhs.Da - rhs.Db);
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int N, A, B;
		cin >> N >> A >> B;
		if (N == 0) break;

		vector<v_data> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i].K >> v[i].Da >> v[i].Db;

		sort(v.begin(), v.end());

		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i].Da > v[i].Db)
			{
				sum += min(B, v[i].K) * v[i].Db;
				int sub = min(B, v[i].K);
				B -= sub;
				v[i].K -= sub;
				sum += min(A, v[i].K) * v[i].Da;
				sub = min(A, v[i].K);
				A -= sub;
				v[i].K -= sub;
			}
			else
			{
				sum += min(A, v[i].K) * v[i].Da;
				int sub = min(A, v[i].K);
				A -= sub;
				v[i].K -= sub;
				sum += min(B, v[i].K) * v[i].Db;
				sub = min(B, v[i].K);
				B -= sub;
				v[i].K -= sub;
			}
		}
		cout << sum << '\n';
	}
}