#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	vector<int> v = { 4,2,3,3,3,3,3,3,3,3 };
	while (true)
	{
		cin >> str;
		if (str == "0") return 0;
		int sum = 0;
		sum += 1;
		for (auto ch : str)
			sum += v[ch - '0']+1;
		cout << sum << '\n';
	}
}