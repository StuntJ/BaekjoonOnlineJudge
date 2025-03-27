#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.size();i++)
	{
		int t = str[i] - '0';
		if (i == 0)
		{
			if(t>=4) cout << bitset<3>(t);
			else if (t>=2) cout << bitset<2>(t);
			else cout << bitset<1>(t);
		}
		else cout << bitset<3>(t);
	}
}