#include <bits/stdc++.h>
#define DIV 1440

using namespace std;

pair<int, int> t[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < 3; i++)
		cin >> t[i].first>>t[i].second;

	int here = t[0].second;
	bool flag = true;;
	for (int i = 1; i <= N*3-1; i++)
	{
		int s = t[i % 3].first;
		int e = t[i % 3].second;
		int next = here + K;
		if (i % 3 == 0) next -= 1440;

		if (next < s)
		{
			flag = false;
			break;
		}
		else if (next >= e)
		{
			here = e;
		}
		else
		{
			here = next;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";
}