#include <bits/stdc++.h>
#define MAX_N 1001
#define INF 987654321
using namespace std;

int cache[MAX_N][MAX_N];
string str, obj;

int solve(int a, int b)
{
	if (a == str.size())
	{
		if (b == obj.size()) return 0;
		else return 1;
	}
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = b; i < obj.size(); i++)
	{
		if (str[a] == obj[i])
		{
			if (i == b) ret = min(solve(a + 1, i + 1), ret);
			else ret = min(solve(a + 1, i + 1) + 1, ret);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));
	getline(cin, str);
	getline(cin, obj);

	for (auto ch : str)
	{
		bool flag = false;
		for (auto ob : obj)
		{
			if (ch == ob)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << -1;
			return 0;
		}
	}

	int ans = solve(0, 0);
	if (ans >= INF) cout << -1;
	else cout << ans;
}