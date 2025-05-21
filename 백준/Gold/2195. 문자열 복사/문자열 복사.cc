#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	string P;
	cin >> S >> P;
	reverse(S.begin(), S.end());
	reverse(P.begin(), P.end());
	//cout << P << '\n';

	int idx = 0;
	int cnt = 0;
	while (idx < P.size())
	{
		int sz = 1;
		while (idx+sz<=P.size()&&S.find(P.substr(idx, sz)) != S.npos)
		{
			sz++;
		}
		cnt++;
		idx += sz-1;
		//cout << idx << ' ';
	}
	cout << cnt; 
}